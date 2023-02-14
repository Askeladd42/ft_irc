/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercore <mmercore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:38:53 by mmercore          #+#    #+#             */
/*   Updated: 2023/02/13 19:56:17 by mmercore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/ft_irc.hpp"

Server::Server(int port, str password, t_sock_conf sock_conf):_password(password), _port(port)
{
	this->errval = nothing;
	set_socketfd(-1 ,sock_conf);
	if (!this->errval && !set_sockopt(sock_conf.level, sock_conf.optname, (const void *)((unsigned long)&sock_conf + (unsigned long)sock_conf.optval), sock_conf.optlen))
	{
		this->errval = nothing;
		// Documenter ceci
		this->_address.sin_family = AF_INET;
		this->_address.sin_addr.s_addr = INADDR_ANY;
		this->_address.sin_port = htons(get_port());
		PRERR "THIS HAPPENED" ENDL;
	}
	if (!this->errval && !call_bind(get_socketfd(), (ssock *)&(this->_address), sizeof((this->_address))))
	{
		PRERR "THIS ALSO" ENDL;
	}
}

Server::~Server()
{
	if (errval != 0 && _socketfd != 0)
		close(_socketfd);	
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
	return (_socketfd);
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

int		Server::call_bind(int fd, ssock * addrptr, socklen_t addrlen)
{
	if (bind(fd, addrptr, addrlen) < 0)
	{
		PRERR "MY ARGS WERE " << fd << " and " << addrptr << " and " << addrlen ENDL;
		PRERR "Errval is " << this->errval ENDL;
		PRERR "port is " << this->_port << " and htons is " << htons(this->_port) ENDL;
		this->errval = bind_fail;
		return (1);
	}
	return (0);
}