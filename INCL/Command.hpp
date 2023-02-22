/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:15:54 by cmaginot          #+#    #+#             */
/*   Updated: 2023/02/21 14:57:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//https://modern.ircdocs.horse/#connection-messages
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

enum	reply_nb {		//temporary attempt to organize the numeric replies, see https://modern.ircdocs.horse/#rplwelcome-001
	RPL_WELCOME = 001,
	RPL_YOURHOST,
	RPL_CREATED,
	RPL_MYINFO,
	RPL_ISUPPORT,
	RPL_BOUNCE = 010,
	RPL_UMODEIS = 221,
	RPL_LUSERCLIENT = 251,
	RPL_LUSEROP,
	RPL_LUSERUNKNOWN,
	RPL_LUSERCHANNELS,
	RPL_LUSERME,
	RPL_ADMINME,
	RPL_ADMINLOC1,
	RPL_ADMINLOC2,
	RPL_ADMINEMAIL,
	RPL_TRYAGAIN = 263,
	RPL_LOCALUSERS = 265,
	RPL_GLOBALUSERS = 266,
	RPL_WHOISCERTFP = 276,
	RPL_NONE = 300,
	RPL_AWAY,
	RPL_USERHOST,
	RPL_UNAWAY,
	RPL_NOWAWAY,
	RPL_WHOREPLY = 352,
	RPL_ENDOFWHO = 315,
	RPL_WHOISREGNICK = 307,
	RPL_WHOISUSER = 311,
	RPL_WHOISSERVER,
	RPL_WHOISOPERATOR,
	RPL_WHOWASUSER,
	RPL_WHOISIDLE = 317,
	RPL_ENDOFWHOIS,
	RPL_WHOISCHANNELS,
	RPL_WHOISSPECIAL,
	RPL_LISTSTART,
	RPL_LIST,
	RPL_LISTEND,
	RPL_CHANNELMODEIS,
	RPL_CREATIONTIME = 329,
	RPL_WHOISACCOUNT,
	RPL_NOTOPIC,
	RPL_TOPIC,
	RPL_TOPICWHOTIME,
	RPL_INVITELIST = 336,			// This numeric should not be confused with RPL_INVEXLIST (346), which is used as a reply to MODE.
	RPL_ENDOFINVITELIST,			// This numeric should not be confused with RPL_ENDOFINVEXLIST (347), which is used as a reply to MODE.
	RPL_WHOISACTUALLY,
	RPL_INVITING = 341,
	RPL_INVEXLIST = 346,
	RPL_ENDOFINVEXLIST,
	RPL_EXCEPTLIST,
	RPL_ENDOFEXCEPTLIST,
	RPL_VERSION = 351,
	RPL_NAMREPLY = 353,
	RPL_ENDOFNAMES = 366,
	RPL_LINKS = 364,
	RPL_ENDOFLINKS,
	RPL_BANLIST = 367,
	RPL_ENDOFBANLIST,
	RPL_ENDOFWHOWAS,
	RPL_INFO = 371,
	RPL_ENDOFINFO = 374,
	RPL_MOTDSTART,
	RPL_MOTD = 372,
	RPL_ENDOFMOTD = 376,
	RPL_WHOISHOST = 378,
	RPL_WHOISMODES,
	RPL_YOUREOPER = 381,
	RPL_REHASHING,
	RPL_TIME = 391,
	ERR_UNKNOWNERROR = 400,
	ERR_NOSUCHNICK,
	ERR_NOSUCHSERVER,
	ERR_NOSUCHCHANNEL,
	ERR_CANNOTSENDTOCHAN,
	ERR_TOOMANYCHANNELS,
	ERR_WASNOSUCHNICK,
	//ERR_NOORIGIN = 409,
	ERR_INPUTTOOLONG = 417,
	//ERR_UNKNOWNCOMMAND = 421,
	ERR_NOMOTD = 422,
	//ERR_ERRONEUSNICKNAME = 432,
	//ERR_NICKNAMEINUSE,
	ERR_USERNOTINCHANNEL = 441,
	ERR_NOTONCHANNEL,
	ERR_USERONCHANNEL,
	//ERR_NOTREGISTERED = 451,
	//ERR_NEEDMOREPARAMS = 461,
	//ERR_ALREADYREGISTERED,
	//ERR_PASSWDMISMATCH = 464,
	//ERR_YOUREBANNEDCREEP,
	ERR_CHANNELISFULL = 471,
	ERR_UNKNOWNMODE,
	ERR_INVITEONLYCHAN,
	ERR_BANNEDFROMCHAN,
	ERR_BADCHANNELKEY,
	ERR_BADCHANMASK,
	ERR_NOPRIVILEGES = 481,
	ERR_CHANOPRIVSNEEDED,
	ERR_CANTKILLSERVER,
	ERR_NOOPERHOST = 491,
	ERR_UMODEUNKNOWNFLAG = 501,
	ERR_USERSDONTMATCH,
	ERR_HELPNOTFOUND = 524,
	ERR_INVALIDKEY,
	RPL_STARTTLS = 670,
	RPL_WHOISSECURE,
	ERR_STARTTLS = 691,
	ERR_INVALIDMODEPARAM = 696,
	RPL_HELPSTART = 704,
	RPL_HELPTXT,
	RPL_ENDOFHELP,
	ERR_NOPRIVS = 723,
	RPL_LOGGEDIN = 900,
	RPL_LOGGEDOUT,
	ERR_NICKLOCKED,
	RPL_SASLSUCCESS,
	ERR_SASLFAIL,
	ERR_SASLTOOLONG,
	ERR_SASLABORTED,
	ERR_SASLALREADY,
	RPL_SASLMECHS,

/* specific replies */
/* NICK message */
	ERR_NONICKNAMEGIVEN = 431,
	ERR_NICKCOLLISION = 436,
/* STATS message */
	RPL_STATSCLINE = 213,
	RPL_STATSHLINE = 244,
	RPL_STATSILINE = 215,
	RPL_STATSKLINE = 216,
	RPL_STATSLLINE = 241,
	RPL_STATSOLINE  = 243,
	RPL_STATSLINKINFO = 211,
	RPL_STATSUPTIME = 242,
	RPL_STATSCOMMANDS = 212,
	RPL_ENDOFSTATS = 219,
/* PRIVMSG message */
	ERR_NORECIPIENT = 411,
	ERR_NOTEXTTOSEND = 412,
	ERR_NOTOPLEVEL = 413,
	ERR_WILDTOPLEVEL = 414
};

#define NO_REPLY Reply()
#define ERR_NOORIGIN Reply(409, "<client> :No origin specified")
#define ERR_UNKNOWNCOMMAND Reply(421, "<client> <command> :Unknown command")
#define ERR_NONICKNAMEGIVEN Reply(431, "<client> :No Nickname Given")
#define ERR_ERRONEUSNICKNAME Reply(432, "<client> <nick> :Erroneus nickname")
#define ERR_NICKNAMEINUSE Reply(433, "<client> <nick> :Nickname is already in use")
#define ERR_NICKCOLLISION Reply(436, "<client> <nick> :Nickname collision")
#define ERR_NOTREGISTERED Reply(451, "<client> :You have not registered")
#define ERR_NEEDMOREPARAMS Reply(461, "<client> <command> :Not enough parameters")
#define ERR_ALREADYREGISTERED Reply(462, "<client> :You may not reregister")
#define ERR_PASSWDMISMATCH Reply(464, "<client> :Password incorrect")
#define ERR_YOUREBANNEDCREEP Reply(465, "<client> :You are banned from this server.")

#define RPL_PING Reply()
#define ERR_TOKENMISMATCH Reply(0, "<client> :token incorrect")





#define USR_STAT_BAN = -2

class User
{
	private:
		bool		_is_connected;
		std::string	_nickname;
		std::string	_username;

	public:
		User(std::string nickname);
		~User();
		bool		get_connected();
		int			get_status();
		std::string	get_nickname();
		std::string	get_username();
		void		set_connected();
		void		set_nickname(std::string newNick);
		void		set_username(std::string newUser);
		bool		user_not_registered(); // todo
};

class Reply
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