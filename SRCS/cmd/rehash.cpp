/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rehash.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/22 16:23:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: REHASH
Parameters: None

The REHASH command is an administrative command which can be used by an operator to force
the local server to re-read and process its configuration file. This may include other data,
such as modules or TLS certificates.

Servers MAY accept, as an optional argument, the name of a remote server that should be
rehashed instead of the current one.

Numeric replies:

RPL_REHASHING (382)
ERR_NOPRIVILEGES (481)
Example:

 REHASH                          ; message from user with operator
                                 status to server asking it to reread
                                 its configuration file.
*/

std::vector<Reply>	Server::rehash(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;
	
	return (reply);
}
