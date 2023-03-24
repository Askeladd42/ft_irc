/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/24 12:57:24 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"
#include "../../INCL/Channel.hpp"

/*
Command: ADMIN
Parameters: [<target>]

The ADMIN command is used to find the name of the administrator
of the given server. If <target> is not given, the information
for the server the client is connected to should be returned.

If <target> is a server, the information for that server is requested.
If <target> is a client, the information for the server that client is
connected to is requested. If <target> is given and a matching server
cannot be found, the server will respond with the ERR_NOSUCHSERVER
numeric and the command will fail.

Wildcards are allowed in the <target> parameter.

Upon receiving an ADMIN command, the given server SHOULD respond with
the RPL_ADMINME, RPL_ADMINLOC1, RPL_ADMINLOC2, and RPL_ADMINEMAIL replies.

Numeric Replies:

ERR_NOSUCHSERVER (402)
RPL_ADMINME (256)
RPL_ADMINLOC1 (257)
RPL_ADMINLOC2 (258)
RPL_ADMINEMAIL (259)
*/

std::vector<Reply>	Server::admin(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	
	if (args.empty() == true || (args.size() == 1 && args[0].compare(this->get_name()))) {
		if (user->get_connected()) {
			reply.push_back(RPL_ADMINME);
			reply.push_back(RPL_ADMINLOC1);
			reply.push_back(RPL_ADMINLOC2);
			reply.push_back(RPL_ADMINEMAIL);
		}
	}
	else
		reply.push_back(ERR_NOSUCHSERVER);
	return (reply);
}
