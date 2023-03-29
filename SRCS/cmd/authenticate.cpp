/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   authenticate.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/28 15:44:31 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCL/User.hpp"
#include "../../INCL/Reply.hpp"
#include "../../INCL/Server.hpp"

/*
Command: AUTHENTICATE

The AUTHENTICATE command is used for SASL authentication between a server and 
a client. The client must support and successfully negotiate the "sasl" client
capability (as listed below in the SASL specifications) before using this command.

The AUTHENTICATE message may be sent from the server to the client.

For the exact semantics of the AUTHENTICATE command and negotiating support for
the "sasl" client capability, please see the IRCv3.1 and IRCv3.2 SASL Authentication
specifications.
*/

std::vector<Reply>	Server::authenticate(User *user, std::vector<std::string> args)
{
	std::vector<Reply> reply;
	(void)user;
	(void)args;
	
	return (reply);
}
