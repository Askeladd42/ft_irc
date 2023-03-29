/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:37:21 by plam              #+#    #+#             */
/*   Updated: 2023/03/28 15:39:19 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/User.hpp"

User::User()
{
	// do not use this;
}

User::User(const User &other)
{
	*this = other;
	// do not use this;
}

User	&User::operator=(const User &other)
{
	if (this != &other) {
		this->_hostname = other._hostname;
		this->_nickname = other._nickname;
		this->_realname = other._realname;
		this->_hostaddr = other._hostaddr;
		this->_username = other._username;
		this->_usermode = other._usermode;
		this->_status_message = other._status_message;
	}
	return *this; // do not use this;
}

User::User(const int fd):_fd(fd),
						_status(-1),
						_connected(false),
						_nickname(""),
						_username(""),
						_realname(""),
						_hostname(""),
						_hostaddr("")
{
	this->_usermode = "";
	this->_status_message = "";
}

User::~User() { }

void	User::set_status(const int newStatus)
{
	this->_status = newStatus;
}

void	User::set_connected()
{
	this->_connected = true;
}

void	User::set_disconnected()
{
	this->_connected = false;
}

void	User::set_user_admin()
{
	set_status(1);
}

void	User::set_user_normal()
{
	set_status(0);
}

void	User::set_nickname(const std::string newNick)
{
	this->_nickname = newNick;
}

void	User::set_username(const std::string newUser)
{
	this->_username = newUser;
}
void	User::set_realname(const std::string newReal)
{
	this->_realname = newReal;
}

void	User::set_hostname(const std::string newHost)
{
	this->_hostname = newHost;
	//temporary, may be replaced/deleted later
}
void	User::set_hostaddr(const std::string newAddr)
{
	this->_hostaddr = newAddr;
	//temporary, may be replaced/deleted later
}

void	User::set_status_message(const std::string new_stat_message)
{
	this->_status_message = new_stat_message;
}

void	User::add_usermode(const char newMod)
{
	this->_usermode.push_back(newMod);
}

bool	User::check_if_mode_is_used(const char mod)
{
	int	i = 0;

	while(this->_usermode[i])
	{
		if (this->_usermode[i] == mod)
			return (true);
		i++;
	}
	return (false);
}

void	User::del_usermode(const char oldMod)
{
	int	i = 0;

	while(this->_usermode[i])
	{
		std::cerr << "hello" << std::endl;
		if (this->_usermode[i] == oldMod)
			this->_usermode.erase(i);
		i++;
	}
}

int	User::get_fd() const
{
	return (this->_fd);
}

int	User::get_status() const
{
	return (this->_status);
}

bool	User::get_connected() const
{
	return (this->_connected);
}

const std::string	&User::get_usermode() const
{
	return (this->_usermode);
}

const std::string&	User::get_nickname() const
{
	return (this->_nickname);
}

const std::string	&User::get_username() const
{
	return (this->_username);
}

const std::string	&User::get_realname() const
{
	return (this->_realname);
}

const std::string	&User::get_hostname() const
{
	return (this->_hostname);
}

const std::string	&User::get_hostaddr() const
{
	return (this->_hostaddr);
}

const std::string	&User::get_status_message() const
{
	return (this->_status_message);
}

std::ostream	&operator<<(std::ostream &ost, const User &other)
{
	ost << "User's username : " << other.get_username() << std::endl 
	<< "User's nickname : " << other.get_nickname() << std::endl
	<< "User's status : " << other.get_status();
	return ost;
}
