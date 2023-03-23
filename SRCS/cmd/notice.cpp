/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:31 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: NOTICE
Parameters: <target>{,<target>} <text to be sent>

The NOTICE command is used to send notices between users, as well as to send notices
to channels. <target> is interpreted the same way as it is for the PRIVMSG command.

The NOTICE message is used similarly to PRIVMSG. The difference between NOTICE and
PRIVMSG is that automatic replies must never be sent in response to a NOTICE message.
This rule also applies to servers – they must not send any error back to the client on
receipt of a NOTICE command. The intention of this is to avoid loops between a client
automatically sending something in response to something it received. This is typically
used by ‘bots’ (a client with a program, and not a user, controlling their actions) and
also for server messages to clients.

One thing for bot authors to note is that the NOTICE message may be interpreted differently
by various clients. Some clients highlight or interpret any NOTICE sent to a channel in the
same way that a PRIVMSG with their nickname gets interpreted. This means that users may be
irritated by the use of NOTICE messages rather than PRIVMSG messages by clients or bots,
and they are not commonly used by client bots for this reason.
*/

std::vector<Reply>	Server::notice(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;
	
	return (reply);
}
