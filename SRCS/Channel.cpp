/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:37:57 by plam              #+#    #+#             */
/*   Updated: 2023/02/14 15:48:45 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/Channel.hpp"

Channel::Channel() { }
Channel::Channel(const Channel &other) {
	*this = other;
}

Channel::~Channel() { }

Channel	&Channel::operator=(const Channel &other) {
	if (this != &other) {		// PEUT ETRE À ENLEVER (je l'ai juste mis pour que ca compile - MAX)
		this->_name = other._name;
	}							//copy function for Channel ?
	return *this;
}

//void	Channel::add(User &user);	// use epoll(epfd, EPOLL_CTL_ADD, fd, *event) for this function ?
//void	Channel::del(User &user);	// use epoll(epfd, EPOLL_CTL_DEL, fd, *event) for this function ?