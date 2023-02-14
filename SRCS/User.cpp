/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:37:21 by plam              #+#    #+#             */
/*   Updated: 2023/02/14 15:20:50 by plam             ###   ########.fr       */
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

void	User::set_nickname(const int newNick)
{
	this->_nickname = newNick;
}

void	User::set_username(const int newUser)
{
	this->_username = newUser;
}
void	User::set_realname(const int newReal)
{
	this->_realname = newReal;
}

void	User::set_hostname(const int newHost)
{
	this->_hostname = newHost;
	//temporary, may be replaced/deleted later
}
void	User::set_hostaddr(const int newAddr)
{
	this->_hostaddr = newAddr;
	//temporary, may be replaced/deleted later
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

std::ostream	&operator<<(std::ostream &ost, const User &other)
{
	ost << "User's username : " << other.get_username() << std::endl 
	<< "User's nickname : " << other.get_nickname() << std::endl
	<< "User's status : " << other.get_status();
	return ost;
}
