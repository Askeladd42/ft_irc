/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:43 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"

#include "../../INCL/Server.hpp"
/*
Command: STATS
Parameters: <query> [<server>]

The STATS command is used to query statistics of a certain server.
The specific queries supported by this command depend on the server
that replies, although the server must be able to supply information
as described by the queries below (or similar).

A query may be given by any single letter which is only checked by the
destination server and is otherwise passed on by intermediate servers,
ignored and unaltered.

The following queries are those found in current IRC implementations and
provide a large portion of the setup and runtime information for that server.
All servers should be able to supply a valid reply to a STATS query which is
consistent with the reply formats currently used and the purpose of the query.

The currently supported queries are:

c - returns a list of servers which the server may connect to or allow connections from;
h - returns a list of servers which are either forced to be treated as leaves or
		allowed to act as hubs;
i - returns a list of hosts which the server allows a client to connect from;
k - returns a list of banned username/hostname combinations for that server;
l - returns a list of the server’s connections, showing how long each connection has
		been established and the traffic over that connection in bytes and messages for
		each direction;
m - returns a list of commands supported by the server and the usage count for each if
		the usage count is non zero;
o - returns a list of hosts from which normal clients may become operators;
u - returns a string showing how long the server has been up.
y - show Y (Class) lines from server’s configuration file;

Need to give this a good look-over. It's probably quite incorrect.

Numeric Replies:

ERR_NOSUCHSERVER (402)
ERR_NEEDMOREPARAMS (461)
ERR_NOPRIVILEGES (481)
ERR_NOPRIVS (723)
RPL_STATSCLINE (213)
RPL_STATSHLINE (244)
RPL_STATSILINE (215)
RPL_STATSKLINE (216)
RPL_STATSLLINE (241)
RPL_STATSOLINE (243)
RPL_STATSLINKINFO (211)
RPL_STATSUPTIME (242)
RPL_STATSCOMMANDS (212)
RPL_ENDOFSTATS (219)
*/

std::vector<Reply>	Server::stats(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;

	return (reply);
}
