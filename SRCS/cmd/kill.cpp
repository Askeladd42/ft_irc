/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/05/19 13:09:47 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: KILL
Parameters: <nickname> <comment>

The KILL command is used to close the connection between a given client and the server
they are connected to. KILL is a privileged command and is available only to IRC Operators.
<nickname> represents the user to be ‘killed’, and <comment> is shown to all users and to
the user themselves upon being killed.

When a KILL command is used, the client being killed receives the KILL message, and the
<source> of the message SHOULD be the operator who performed the command. The user being
killed and every user sharing a channel with them receives a QUIT message representing that
they are leaving the network. The <reason> on this QUIT message typically has the form:
"Killed (<killer> (<reason>))" where <killer> is the nickname of the user who performed the
KILL. The user being killed then receives the ERROR message, typically containing a <reason>
of "Closing Link: <servername> (Killed (<killer> (<reason>)))". After this, their connection
is closed.

If a KILL message is received by a client, it means that the user specified by <nickname>
is being killed. With certain servers, users may elect to receive KILL messages created for
other users to keep an eye on the network. This behavior may also be restricted to operators.

Clients can rejoin instantly after this command is performed on them. However, it can serve
as a warning to a user to stop their activity. As it breaks the flow of data from the user,
it can also be used to stop large amounts of ‘flooding’ from abusive users or due to accidents.
Abusive users may not care and promptly reconnect and resume their abusive behaviour. In
these cases, opers may look at the KLINE command to keep them from rejoining the network
for a longer time.

As nicknames across an IRC network MUST be unique, if duplicates are found when servers join,
one or both of the clients MAY be KILLed and removed from the network. Servers may also handle
this case in alternate ways that don’t involve removing users from the network.

Servers MAY restrict whether specific operators can remove users on other servers (remote users).
If the operator tries to remove a remote user but is not privileged to, they should receive the
ERR_NOPRIVS (723) numeric.

<comment> SHOULD reflect why the KILL was performed. For user-generated KILLs, it is up to the
user to provide an adequate reason.

Numeric Replies:

ERR_NOSUCHSERVER (402)
ERR_NEEDMOREPARAMS (461)
ERR_NOPRIVILEGES (481)
ERR_NOPRIVS (723)
NOTE: The KILL message is weird, and I need to look at it more closely, add some examples, etc.
*/

std::vector<Reply>	Server::kill(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	int usr_targeted = 0;

	if (user->get_status() == USR_STAT_BAN)
		reply.push_back(ERR_YOUREBANNEDCREEP);
	else if (user->get_connected() == false)
		reply.push_back(ERR_NOTREGISTERED);
	else if (args.empty() == true || args[0].compare("") == 0)
	{
		reply.push_back(ERR_NEEDMOREPARAMS);
		reply[reply.size() - 1].add_arg("KILL", "command");
	}
	else if (user->check_if_mode_is_used('o') == false)
		reply.push_back(ERR_NOPRIVILEGES);
	else
	{
		User *usr = find_user_by_nickname(args[usr_targeted]);

		if (usr == NULL)
		{
			reply.push_back(ERR_NOSUCHNICK);
			reply[reply.size() - 1].add_arg(args[usr_targeted], "nickname");
		}
		else
		{
			usr->set_kicked(1);
			this->errval = user_close;
		}

		for (std::vector<Reply>::iterator it = reply.begin(); it != reply.end(); it++)
		{
			it->add_user(user);
			it->prep_to_send(1);
		}
	}
	return (reply);
}
