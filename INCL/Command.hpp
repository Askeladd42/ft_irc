/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/01/25 11:28:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//https://modern.ircdocs.horse/#connection-messages
#include <vector>
#include <string>
# include <iostream>


class User
{
	public:
		User();
		~User();
};

class Reply
{
	public:
		Reply();
		~Reply();
};

class Server
{
	public :
		std::vector<Reply>	command(User &user, std::string commandName, std::vector<std::string> args);

	private :
		std::vector<Reply>	cap(User &user, std::vector<std::string> args);
		std::vector<Reply>	authenticate(User &user, std::vector<std::string> args);
		std::vector<Reply>	pass(User &user, std::vector<std::string> args);
		std::vector<Reply>	nick(User &user, std::vector<std::string> args);
		std::vector<Reply>	user(User &user, std::vector<std::string> args);
		std::vector<Reply>	ping(User &user, std::vector<std::string> args);
		std::vector<Reply>	pong(User &user, std::vector<std::string> args);
		std::vector<Reply>	oper(User &user, std::vector<std::string> args);
		std::vector<Reply>	quit(User &user, std::vector<std::string> args);
		std::vector<Reply>	error(User &user, std::vector<std::string> args);
		std::vector<Reply>	join(User &user, std::vector<std::string> args);
		std::vector<Reply>	part(User &user, std::vector<std::string> args);
		std::vector<Reply>	topic(User &user, std::vector<std::string> args);
		std::vector<Reply>	names(User &user, std::vector<std::string> args);
		std::vector<Reply>	list(User &user, std::vector<std::string> args);
		std::vector<Reply>	invite(User &user, std::vector<std::string> args);
		std::vector<Reply>	kick(User &user, std::vector<std::string> args);
		std::vector<Reply>	motd(User &user, std::vector<std::string> args);
		std::vector<Reply>	version(User &user, std::vector<std::string> args);
		std::vector<Reply>	admin(User &user, std::vector<std::string> args);
		std::vector<Reply>	connect(User &user, std::vector<std::string> args);
		std::vector<Reply>	lusers(User &user, std::vector<std::string> args);
		std::vector<Reply>	time(User &user, std::vector<std::string> args);
		std::vector<Reply>	stats(User &user, std::vector<std::string> args);
		std::vector<Reply>	help(User &user, std::vector<std::string> args);
		std::vector<Reply>	info(User &user, std::vector<std::string> args);
		std::vector<Reply>	mode(User &user, std::vector<std::string> args);
		std::vector<Reply>	privmsg(User &user, std::vector<std::string> args);
		std::vector<Reply>	notice(User &user, std::vector<std::string> args);
		std::vector<Reply>	who(User &user, std::vector<std::string> args);
		std::vector<Reply>	whois(User &user, std::vector<std::string> args);
		std::vector<Reply>	whowas(User &user, std::vector<std::string> args);
		std::vector<Reply>	kill(User &user, std::vector<std::string> args);
		std::vector<Reply>	rehash(User &user, std::vector<std::string> args);
		std::vector<Reply>	restart(User &user, std::vector<std::string> args);
		std::vector<Reply>	squit(User &user, std::vector<std::string> args);
		std::vector<Reply>	away(User &user, std::vector<std::string> args);
		std::vector<Reply>	links(User &user, std::vector<std::string> args);
		std::vector<Reply>	userhost(User &user, std::vector<std::string> args);
		std::vector<Reply>	wallops(User &user, std::vector<std::string> args);

};//!Server

typedef struct	s_command
{
	std::string	commandName;
	std::vector<Reply>	(Server::*commands)(User &user, std::vector<std::string> args);
}				t_command;










// utils TODO :
bool is_nickname_free(std::string nickname); // server function on user list
/*
	search on all user.
		if someone have this nickname 
			return false
		else
			return true
*/

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