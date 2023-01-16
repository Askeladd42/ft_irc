/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:37:21 by plam              #+#    #+#             */
/*   Updated: 2023/01/16 14:41:59 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/User.hpp"

void				User::set_status(const int newStatus)
{
	this->_status = newStatus;
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

int	User::get_fd() const
{
	return (this->_fd);
}

int	User::get_status() const
{
	return (this->_status);
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