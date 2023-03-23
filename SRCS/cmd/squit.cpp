/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squit.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:42 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: SQUIT
Parameters: <server> <comment>

The SQUIT command disconnects a server from the network. SQUIT is a privileged
command and is only available to IRC Operators. <comment> is the reason why the
server link is being disconnected.

In a traditional spanning-tree topology, the command gets forwarded to the specified
server. And the link between the specified server and the last server to propagate
the command gets broken.

Numeric replies:

ERR_NOSUCHSERVER (402)
ERR_NEEDMOREPARAMS (461)
ERR_NOPRIVILEGES (481)
ERR_NOPRIVS (723)
*/

std::vector<Reply>	Server::squit(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;
	
	return (reply);
	// does nothing, we only have one server
}
