/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:21 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: LINKS
Parameters: None

With LINKS, a user can list all servers which are known by the server answering the query,
usually including the server itself.

In replying to the LINKS message, a server MUST send replies back using zero or more
RPL_LINKS (364) messages and mark the end of the list using a RPL_ENDOFLINKS (365) message.

Servers MAY omit some or all servers on the network, including itself.

Numeric Replies:

RPL_LINKS (364)
RPL_ENDOFLINKS (365)
*/

std::vector<Reply>	Server::links(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;
	
	return (reply);
}
