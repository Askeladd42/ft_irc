/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/28 16:31:38 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: OPER
Parameters: <name> <password>

The OPER command is used by a normal user to obtain IRC operator privileges. Both
parameters are required for the command to be successful.

If the client does not send the correct password for the given name, the server
replies with an ERR_PASSWDMISMATCH message and the request is not successful.

If the client is not connecting from a valid host for the given name, the server
replies with an ERR_NOOPERHOST message and the request is not successful.

If the supplied name and password are both correct, and the user is connecting from
a valid host, the RPL_YOUREOPER message is sent to the user-> The user will also
receive a MODE message indicating their new user modes, and other messages may be sent.

The <name> specified by this command is separate to the accounts specified by SASL
authentication, and is generally stored in the IRCd configuration.

Numeric Replies:

ERR_NEEDMOREPARAMS (461)
ERR_PASSWDMISMATCH (464)
ERR_NOOPERHOST (491)
RPL_YOUREOPER (381)
*/

std::vector<Reply>	Server::oper(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;

	if (user->get_status() == USR_STAT_BAN)
		reply.push_back(ERR_YOUREBANNEDCREEP);
	else if (user->get_connected() == false)
		reply.push_back(ERR_NOTREGISTERED);
	else if (*(args.begin()) == "" && (*(args.end()) == "" || args.size() == 0))
		reply.push_back(ERR_NEEDMOREPARAMS);
	else if (args[1].compare(this->_password))		//(need to add _oper_pass or something on server)
		reply.push_back(ERR_PASSWDMISMATCH);
	else if (!args[0].compare(user->get_hostaddr()))	//temporary, need a adequate comparing value for hostname
		reply.push_back(ERR_NOOPERHOST);
	else
		reply.push_back(RPL_YOUREOPER);
	reply[0].add_user(user);
	reply[0].prep_to_send(1);
	return (reply);
}
