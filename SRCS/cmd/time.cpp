/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:44 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: TIME
Parameters: [<server>]

The TIME command is used to query local time from the specified server.
If the server parameter is not given, the server handling the command
must reply to the query.

Numeric Replies:

ERR_NOSUCHSERVER (402)
RPL_TIME (391)
*/

std::vector<Reply>	Server::time(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	int					target = 0;
	(void)user;

	if (args.empty() == true || args[target].compare(this->_name))
		reply.push_back(RPL_TIME);
	else
		reply.push_back(ERR_NOSUCHSERVER);
	return (reply);
}
