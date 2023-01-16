/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercore <mmercore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:38:53 by mmercore          #+#    #+#             */
/*   Updated: 2023/01/16 15:38:50 by mmercore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/ft_irc.hpp"

Server::Server(int port, int password, t_sock_conf sock_conf):_port(port), _password(password)
{
	this->errval = 0;
	set_socketfd(sock_conf);
}

Server::~Server()
{
	if (errval != 0 && socketfd != 0)
		close(_socketfd);	
}

int		Server::get_port()
{
	return (port);	
}

void	Server::set_port(int port)
{
	this->port = port;	
}

int		Server::get_socketfd()
{
	return (_socketfd);
}

void	Server::set_socketfd(int socketfd, t_sock_conf sock_conf)
{
	this->_socketfd = socketfd;
	if (socket < 0)
		this->_socketfd = socket(sock_conf.domain, sock_conf.type, sock_conf.protocol);
	if (socket < 0)
	{
		PRERR "SYSCALL TO MAKE SOCKET FAILED" ENDL;
		this->errval = socket_fail;
	}
}

