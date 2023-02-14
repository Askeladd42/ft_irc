/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercore <mmercore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:37:57 by plam              #+#    #+#             */
/*   Updated: 2023/02/13 19:33:05 by mmercore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/Channel.hpp"

Channel::Channel() { }
Channel::Channel(const Channel &other) {
	*this = other;
}

Channel::~Channel() { }

Channel	&Channel::operator=(const Channel &other) {
	if (this != &other)
		return *this; // ENLEVER (je l'ai juste mis pour que ca compile - MAX)
		//copy function for Channel ?
	return *this;
}

//void	Channel::add(User &user);	// use epoll(epfd, EPOLL_CTL_ADD, fd, *event) for this function ?
//void	Channel::del(User &user);	// use epoll(epfd, EPOLL_CTL_DEL, fd, *event) for this function ?