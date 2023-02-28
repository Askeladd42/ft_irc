/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercore <mmercore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:38:53 by mmercore          #+#    #+#             */
/*   Updated: 2023/02/28 13:39:20 by mmercore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/ft_irc.hpp"
#include <string.h>

Server::Server(int port, str password, t_sock_conf sock_conf):_password(password), _port(port)
{
	this->errval = nothing;
	set_socketfd(-1 ,sock_conf);
	if (!this->errval && !set_sockopt(sock_conf.level, sock_conf.optname, (const void *)((unsigned long)&sock_conf + (unsigned long)sock_conf.optval), sock_conf.optlen))
	{
		//this->errval = nothing;
		// Documenter ceci
		this->_address.sin_family = AF_INET;
		// Peut venir de n'importe quelle addresse
		this->_address.sin_addr.s_addr = INADDR_ANY;
		// 
		this->_address.sin_port = htons(get_port());
		PRERR "SETSOCKOPT HAPPENED AND ERRVAL " << this->errval ENDL;
	}
	if (!this->errval && !call_fcntl(get_socketfd(), sock_conf.optname2))
	{
		PRERR "FCNTL HAPPENED AND SUCCESS" ENDL
	}
	if (!this->errval && !call_bind(get_socketfd(), (ssock *)&(this->_address), sizeof((this->_address))))
	{
		PRERR "BIND SUCCESS" ENDL;
	}
	if (!this->errval && !call_listen(get_socketfd()))
	{
		PRERR "LISTEN SUCCESS" ENDL;
	}
	polling_loop();
}

Server::~Server()
{
	if (this->_socketfd != 0)
		close(_socketfd);
	if (this->errval == 0)
		PRINT "Server closed successfully with no issues" ENDL
	else
		PRINT "Error: Safe close. The errval is " << get_errval(this->errval) << " and the errno is " << strerror(errno) ENDL
}

str			Server::get_errval(t_serv_error errval) const
{
	switch (errval)
	{
		case nothing:		return("nothing");
		case syscall_fail:	return("syscall_fail");
		case socket_fail:	return("socket_fail");
		case sock_opt_fail:	return("sock_opt_fail");
		case fcntl_fail:	return("fcntl_fail");
		case bind_fail:		return("bind_fail");
		case listen_fail:	return("listen_fail");
		case poll_fail:		return("poll_fail");
		case timeout:		return("timeout");
	}
	return ("nothing");
}

str			Server::get_password() const
{
	return	(this->_password);
}


int		Server::get_port() const
{
	return (this->_port);
}

void	Server::set_port(int port)
{
	this->_port = port;	
}

int		Server::get_socketfd() const
{
	return (this->_socketfd);
}

void	Server::set_socketfd(int socketfd, t_sock_conf sock_conf)
{
	this->_socketfd = socketfd;
	if (this->_socketfd < 0)
		this->_socketfd = socket(sock_conf.domain, sock_conf.type, sock_conf.protocol);
	if (this->_socketfd < 0)
	{
		PRERR "SYSCALL TO MAKE SOCKET FAILED" ENDL;
		this->errval = socket_fail;
	}
}

int		Server::set_sockopt(int level, int optname, const void *optval, socklen_t optlen)
{
	if (setsockopt(this->_socketfd, level, optname, optval, optlen) == -1)
	{
		PRERR "FAILED TO SET SOCKET OPTION" ENDL;
		this->errval = sock_opt_fail;
		return (1);
	}
	return (0);
}

int			Server::call_fcntl(int fd, int request)
{
	int flags;

	flags = fcntl(fd, F_GETFL, 0);
	if (flags == -1 || fcntl(fd, F_SETFL, flags | request) < 0)
	{
		PRERR "FAILED TO CALL FCNTL" ENDL
		this->errval = fcntl_fail;
		return (1);
	}
	return (0);
}


int		Server::call_bind(int fd, ssock * addrptr, socklen_t addrlen)
{
	if (bind(fd, addrptr, addrlen) < 0)
	{
		this->errval = bind_fail;
		return (1);
	}
	PRERR "ONE SUCCESS BIND" ENDL
	return (0);
}

int		Server::call_listen(int fd, int backlog_hint)
{
	if (listen(fd, backlog_hint) < 0)
	{
		this->errval = listen_fail;
		return(1);
	}
	return (0);
}

int		Server::polling_loop()
{
	// return (0);
	int pol_ret, fd_counter, fd_cursor, new_fd, recv_ret;
	char buffer[MAX_LINE_SIZE];

	fd_counter = 1;
	fd_cursor = 0;
	new_fd = -1;
	recv_ret = 1;
	this->fds[0].fd = get_socketfd();
	this->fds[0].events = POLLIN;
	pol_ret = 0;
	while(this->errval == 0)
	{
		PRERR "Polling..." ENDL;
		pol_ret = poll(this->fds, fd_counter,DEFAULT_TIMEOUT);

		if (pol_ret < 0)
		{
			PRERR "POLL FAIL" ENDL
			this->errval = poll_fail;
			return (1);
		}
		else if (pol_ret == 0)
		{
			PRERR "TIMEOUT" ENDL;
			this->errval = timeout;
			return (1);
		}
		else
		{
			while (fd_cursor < fd_counter)
			{
				//if (fds[fd_cursor].revents == 0)
				//	continue;
				// Ajouter erreurs
				if (fds[fd_cursor].fd == get_socketfd())
				{
					//choses
					new_fd = 1;
					while (new_fd != -1)
					{
						new_fd = accept(get_socketfd(), NULL, NULL);
						// Errors
						fds[fd_counter].fd = new_fd;
						fds[fd_counter].events = POLLIN;
						PRERR "NEW CONNECTION HIHI" ENDL;
						send(fds[fd_counter].fd, "Hi Bitch, Welcome to IRC!!!", 27, 0);
						PRERR "New fd is now " << new_fd ENDL
						if (new_fd != -1)
							fd_counter++;
					}
				}
				else
				{
					PRERR "TEST" ENDL
					recv_ret = 1;
					while (recv_ret > 0)
					{
						PRERR "TEST" ENDL
						recv_ret = recv(fds[fd_cursor].fd, buffer, sizeof(buffer), 0);
						//send(fds[fd_cursor].fd, buffer, sizeof(buffer), 0);

						PRERR "Received this " << buffer ENDL;
						// Errors
					}
				}
				fd_cursor++;
			}
		}
	}
	return (0);
}

User	*Server::find_user(int fd)
{
	for (std::vector<User *>::iterator it = _usr_list.begin(); it != _usr_list.end(); it++)
	{
		if ((*it)->get_fd() == fd)
			return (*it);
	}

	return (NULL);
}

void	Server::run_line(int fd, std::string line)
{
	User *user = find_user(fd);
	if (user == NULL)
		return ;
	std::vector<std::string>	args = pars_line(line);
	std::string					cmd = args[0];
	args.erase(args.begin());
	std::vector<Reply>			rpls = command(user, cmd, args);
	for (std::vector<Reply>::iterator it = rpls.begin(); it != rpls.end(); it++)
		send_message(user, it->get_message());
}

std::vector<std::string>	Server::pars_line(std::string line)
{
	size_t						pos;
	std::string					word;
	std::vector<std::string>	args;
	while (line.length() != 0)
	{
		pos = line.find(' ');
		if (pos == std::string::npos)
		{
			word = line;
			line.erase(line.begin(), line.end());
		}
		else
		{
			word = line.substr(0, pos);
			line.erase(line.begin(), line.begin() + pos + 1);
		}
		args.push_back(word);
	}
	return args;
}

void	Server::send_message(User *user, std::string message)
{
	std::cout << "send message to fd " << user->get_fd() << " : " << message << std::endl; // push all rpls on file instead of cout
}

std::vector<Reply>	Server::command(User *user, std::string commandName, std::vector<std::string> args)
{
	t_command	t[] =
	{
		{"CAP", &Server::cap},
		{"AUTHENTICATE", &Server::authenticate},
		{"PASS", &Server::pass},
		{"NICK", &Server::nick},
		{"USER", &Server::user},
		{"PING", &Server::ping},
		{"PONG", &Server::pong},
		{"OPER", &Server::oper},
		{"QUIT", &Server::quit},
		{"ERROR", &Server::error},
		{"JOIN", &Server::join},
		{"PART", &Server::part},
		{"TOPIC", &Server::topic},
		{"NAMES", &Server::names},
		{"LIST", &Server::list},
		{"INVITE", &Server::invite},
		{"KICK", &Server::kick},
		{"MOTD", &Server::motd},
		{"VERSION", &Server::version},
		{"ADMIN", &Server::admin},
		{"CONNECT", &Server::connect},
		{"LUSERS", &Server::lusers},
		{"TIME", &Server::time},
		{"STATS", &Server::stats},
		{"HELP", &Server::help},
		{"INFO", &Server::info},
		{"MODE", &Server::mode},
		{"PRIVMSG", &Server::privmsg},
		{"NOTICE", &Server::notice},
		{"WHO", &Server::who},
		{"WHOIS", &Server::whois},
		{"WHOWAS", &Server::whowas},
		{"KILL", &Server::kill},
		{"REHASH", &Server::rehash},
		{"RESTART", &Server::restart},
		{"SQUIT", &Server::squit},
		{"AWAY", &Server::away},
		{"LINKS", &Server::links},
		{"USERHOST", &Server::userhost},
		{"WALLOPS", &Server::wallops}
	};

	for (int i = 0; i < 40; i++)
	{
		if (t[i].commandName == commandName)
			return (this->*t[i].commands) (user, args);
	}
	std::vector<Reply>	reply;
	reply.push_back(ERR_UNKNOWNCOMMAND);
	reply[0].add_user(user);
	reply[0].add_arg(commandName);
	return (reply);
}

