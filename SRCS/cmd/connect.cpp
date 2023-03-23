/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:09 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: CONNECT
Parameters: <target server> [<port> [<remote server>]]

The CONNECT command forces a server to try to establish a new connection
to another server. CONNECT is a privileged command and is available only
to IRC Operators. If a remote server is given, the connection is attempted
by that remote server to <target server> using <port>.

Numeric Replies:

ERR_NOSUCHSERVER (402)
ERR_NEEDMOREPARAMS (461)
ERR_NOPRIVILEGES (481)
ERR_NOPRIVS (723)
*/

std::vector<Reply>	Server::connect(User *user, std::vector<std::string> args) // do not use, no connection between server in subject
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;
	
	return (reply);
	// do nothing is command connect is called (not required in subject)
}
