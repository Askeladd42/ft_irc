/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/01/30 17:07:58 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//https://modern.ircdocs.horse/#connection-messages
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

class User
{
	private:
		bool	is_connected;

	public:
		User();
		~User();
		bool	get_connected();
		void	set_connected();
};

class Reply			// PM : to do in Command.cpp
{
	private:
		int				_value;
		std::string		_message;

	public:
		Reply();
		Reply(int value, std::string message);
		Reply(const Reply &reply);
		~Reply();
		Reply		&operator=(const Reply &other);
		void		add_arg(std::string arg);
		int			get_value() const;
		std::string	get_message() const;

};

#define ERR_NEEDMOREPARAMS Reply(461, "<client> <command> :Not enough parameters")
#define ERR_ALREADYREGISTERED Reply(462, "<client> :You may not reregister")
#define ERR_PASSWDMISMATCH Reply(464, "<client> :Password incorrect")

class Server
{
	private:
		std::string	_password; // TO DELETE

	public:
		Server(); // TO DELETE
		~Server(); // TO DELETE

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