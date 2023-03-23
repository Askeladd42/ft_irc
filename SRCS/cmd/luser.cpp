/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luser.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:23 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: LUSERS
Parameters: None

Returns statistics about local and global users, as numeric replies.

Servers MUST reply with RPL_LUSERCLIENT and RPL_LUSERME, and SHOULD
also include all those defined below.

Clients SHOULD NOT try to parse the free-form text in the trailing
parameter, and rely on specific parameters instead.

RPL_LUSERCLIENT (251)
RPL_LUSEROP (252)
RPL_LUSERUNKNOWN (253)
RPL_LUSERCHANNELS (254)
RPL_LUSERME (255)
RPL_LOCALUSERS (265)
RPL_GLOBALUSERS (266)
*/

std::vector<Reply>	Server::lusers(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;

	std::vector<User *>::iterator		it = this->_usr_list.begin();
	// Ici pb avec std c98, fix svp
	(void)user;
	if (args.empty() == true) {
		reply.push_back(RPL_LUSERCLIENT);
		while (it != this->_usr_list.end())
			std::cout << (*it)->get_username() << std::endl;		// put the list of username of the usrs to compare
		reply.push_back(RPL_LUSERME);
	}
	else
		reply.push_back(RPL_LUSERUNKNOWN);
	return (reply);
}
