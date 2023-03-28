/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/27 17:53:51 by cmaginot         ###   ########.fr       */
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
	(void)args;

	reply.push_back(ERR_UNKNOWNCOMMAND);
	reply[0].add_user(user);
	reply[0].add_arg("CONNECT", "command");
	reply[0].prep_to_send(1);
	return (reply);
	// do nothing is command connect is called (not required in subject)
}
