/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallops.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: WALLOPS
Parameters: <text>

The WALLOPS command is used to send a message to all currently connected users who have set the ‘w’ user mode for themselves. The <text> SHOULD be non-empty.

Servers MAY echo WALLOPS messages to their sender even if they don’t have the ‘w’ user mode.

Servers MAY send WALLOPS only to operators.

Servers may generate it themselves, and MAY allow operators to send them.

Numeric replies:

ERR_NEEDMOREPARAMS (461)
ERR_NOPRIVILEGES (481)
ERR_NOPRIVS (723)
Examples:

 :csd.bu.edu WALLOPS :Connect '*.uiuc.edu 6667' from Joshua
                                 ;WALLOPS message from csd.bu.edu announcing
                                 a CONNECT message it received and acted
                                 upon from Joshua.

*/

std::vector<Reply>	Server::wallops(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;
	
	return (reply);
}
