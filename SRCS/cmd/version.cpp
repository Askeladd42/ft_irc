/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/05/24 18:02:29 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: VERSION
Parameters: [<target>]

The VERSION command is used to query the version of the software and the 
RPL_ISUPPORT parameters of the given server. If <target> is not given, the 
information for the server the client is connected to should be returned.

If <target> is a server, the information for that server is requested. If 
<target> is a client, the information for the server that client is connected 
to is requested. If <target> is given and a matching server cannot be found, 
the server will respond with the ERR_NOSUCHSERVER numeric and the command will fail.

Wildcards are allowed in the <target> parameter.

Upon receiving a VERSION command, the given server SHOULD respond with one 
RPL_VERSION reply and one or more RPL_ISUPPORT replies.

Numeric Replies:

ERR_NOSUCHSERVER (402)
RPL_ISUPPORT (005)
RPL_VERSION (351)
*/

std::vector<Reply>	Server::version(User *user, std::vector<std::string> args)
{
	std::vector<Reply>	reply;
	int 				target = 0;

	if (user->get_status() == USR_STAT_BAN)
		reply.push_back(ERR_YOUREBANNEDCREEP);
	else if (user->get_connected() == false)
		reply.push_back(ERR_NOTREGISTERED);
	else if (args.empty() == true || args[target].compare("") == 0 || this->_name.compare(args[target]) == true)
	{
		reply.push_back(RPL_VERSION);
		reply[reply.size()-1].add_arg(this->get_version(), "version");
		reply[reply.size()-1].add_arg(this->get_name(), "server");
		reply[reply.size()-1].add_arg(":neco_irc test server", "comments");
	}
	else
	{
		reply.push_back(ERR_NOSUCHSERVER);
		reply[reply.size()-1].add_arg(args[target], "server name");
	}
	for (std::vector<Reply>::iterator it = reply.begin(); it != reply.end(); it++)
	{
		it->add_user(user);
		it->prep_to_send(1);
	}
	return (reply);
}