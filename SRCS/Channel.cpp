/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:37:57 by plam              #+#    #+#             */
/*   Updated: 2023/01/27 16:22:03 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/Channel.hpp"

Channel::Channel() { }
Channel::Channel(const Channel &other) {
	*this = other;
}

Channel::~Channel();

Channel::Channel	&operator=(const Channel &other);

void	Channel::add(User &user);
void	Channel::del(User &user);