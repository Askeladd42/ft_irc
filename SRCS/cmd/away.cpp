/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   away.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:03 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: AWAY
Parameters: [ <text> ]

The AWAY command lets clients indicate that their user is away. If this command is
sent with a nonempty parameter (the ‘away message’) then the user is set to be away.
If this command is sent with no parameters, or with the empty string as the parameter,
the user is no longer away.

The server acknowledges the change in away status by returning the RPL_NOWAWAY (306)
and RPL_UNAWAY (305) numerics. If the IRCv3 away-notify capability has been requested
by a client, the server MAY also send that client AWAY messages to tell them how the
away status of other users has changed.

Servers SHOULD notify clients when a user they’re interacting with is away when relevant,
including sending these numerics:

RPL_AWAY (301), with the away message, when a PRIVMSG command is directed at the away user
(not to a channel they are on).
RPL_AWAY (301), with the away message, in replies to WHOIS messages.
In the RPL_USERHOST (302) numeric, as the + or - character.
In the RPL_WHOREPLY (352) numeric, as the H or G character.
Numeric Replies:

RPL_UNAWAY (305)
RPL_NOWAWAY (306)
*/

std::vector<Reply>	Server::away(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;
	
	return (reply);
}
