/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:37:21 by plam              #+#    #+#             */
/*   Updated: 2023/01/13 13:51:41 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/Client.hpp"

void				Client::set_status(const int newStatus) {
	this->_status = newStatus;
}

void				Client::set_nickname(const int newNick) {
	this->_nickname = newNick;
}

void				Client::set_username(const int newUser) {
	this->_username = newUser;
}
void				Client::set_realname(const int newReal) {
	this->_realname = newReal;
}

int					Client::get_fd() const {
	return (this->_fd);
}

int					Client::get_status() const {
	return (this->_status);
}

const std::string&	Client::get_nickname() const {

}

const std::string	&Client::get_username() const {
	return (this->_username);
}

const std::string	&Client::get_realname() const {
	return (this->_realname);
}

const std::string	&Client::get_hostname() const {
	return (this->_hostname);
}