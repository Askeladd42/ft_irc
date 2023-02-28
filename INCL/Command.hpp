/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/02/27 19:13:21 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//https://modern.ircdocs.horse/#connection-messages
# include "ft_irc.hpp"
//function TODO
bool is_nickname_valid(std::string nickname); // server function on user list
/*
	search on all character.
		if forbiden character 
			return false
	search on forbidden nickname (optional)
		if (nickname == forbidden nickname) (optional)
			return false (optional)
	return true
*/
bool is_nickname_free(std::string nickname); // server function on user list
/*
	search on all user.
		if someone have this nickname 
			return false
		else
			return true
*/

bool is_a_server(std::string target); // server fonction on server list // may only return user name due to subject
/*
	if server_name == target
		return true
	return false
*/

bool search_motd(std::vector<Reply> &v_reply); // server fonction on message of the day var
/*
	if _message_of_the_day = ""
		return (false)
	v_reply.push_back(RPL_MOTDSTART);
	for (std::vector<std::string>::iterator it = _message_of_the_day.begin(); \
										it != _message_of_the_day.end(); it++)
	{
		v_reply.push_back(RPL_MOTD);
	}
	v_reply.push_back(RPL_ENDOFMOTD);
*/

bool token_is_valid(std::string token);

bool target_is_valid(std::string target);

//function TODO