/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: HELP
Parameters: [<subject>]

The HELP command is used to return documentation about the IRC server and the IRC
commands it implements.

When receiving a HELP command, servers MUST either: reply with a single
ERR_HELPNOTFOUND (524) message; or reply with a single RPL_HELPSTART (704)
message, then arbitrarily many RPL_HELPTXT (705) messages, then a single
RPL_ENDOFHELP (706). Servers MAY return the RPL_HELPTXT (705) form for unknown
subjects, especially if their reply would not fit in a single line.

The RPL_HELPSTART (704) message SHOULD be some sort of title and the first
RPL_HELPTXT (705) message SHOULD be empty. This is what most servers do today.

Servers MAY define any <subject> they want. Servers typically have documentation
for most of the IRC commands they support.

Clients SHOULD gracefully handle older servers that reply to HELP with a set of
NOTICE messages. On these servers, the client may try sending the HELPOP command
(with the same syntax specified here), which may return the numeric-based reply.

Clients SHOULD also gracefully handle servers that reply to HELP with a set of
290/291/292/293/294/295 numerics.

Numerics:

ERR_HELPNOTFOUND (524)
RPL_HELPSTART (704)
RPL_HELPTXT (705)
RPL_ENDOFHELP (706)
*/

std::vector<Reply>	Server::help(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;

	if (user->get_connected() == true) {
		if (args.size() == 0) {
			reply.push_back(RPL_HELPSTART);
			reply.push_back(RPL_ENDOFHELP);
		}
		else if (args.size() == 1) {
			reply.push_back(RPL_HELPSTART);
			while (user->get_status())			// temporary :  while help text is shown, need client/user treatment for it ?
				reply.push_back(RPL_HELPTXT);
			reply.push_back(RPL_ENDOFHELP);
		}
		else
			reply.push_back(ERR_HELPNOTFOUND);
	}
	return (reply);
}
