/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userhost.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/28 18:37:22 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: USERHOST
Parameters: <nickname>{ <nickname>}

The USERHOST command is used to return information about users with the given nicknames.
The USERHOST command takes up to five nicknames, each a separate parameters. The nicknames
are returned in RPL_USERHOST (302) numerics.

Numeric Replies:

ERR_NEEDMOREPARAMS (461)
RPL_USERHOST (302)
Command Examples:

  USERHOST Wiz Michael Marty p    ;USERHOST request for information on
                                  nicks "Wiz", "Michael", "Marty" and "p"
Reply Examples:

  :ircd.stealth.net 302 yournick :syrk=+syrk@millennium.stealth.net
                                  ; Reply for user syrk
*/

std::vector<Reply>	Server::userhost(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	if (args.size() == 0)
		reply.push_back(ERR_NEEDMOREPARAMS);
	else
	{
		if (args.size() <= 5)
		{
			for (std::vector<std::string>::iterator itA = args.begin(); itA != args.end(); itA++)
			{
				for (std::vector<User *>::iterator itL = this->_usr_list.begin(); itL != this->_usr_list.end(); itL++)
				{
					if (*itA == (*itL)->get_nickname())
						reply.push_back(RPL_USERHOST);
				}
			}
		}
	}

	reply[0].add_user(user);
	reply[0].prep_to_send(1);
	return (reply);
}
