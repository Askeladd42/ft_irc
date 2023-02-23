/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:32:30 by cmaginot          #+#    #+#             */
/*   Updated: 2023/02/23 17:40:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

#include "../INCL/User.hpp"

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

#define RPL_PONG Reply()
#define ERR_TOKENMISMATCH Reply(0, "<client> :token incorrect")




class Reply
{
	private:
		int				_value;
		std::string		_message;
		User			*_user;

	public:
		Reply();
		Reply(int value, std::string message);
		Reply(const Reply &reply);
		~Reply();
		Reply		&operator=(const Reply &other);
		void		add_arg(std::string arg);
		void		add_user(User *user);
		int			get_value() const;
		std::string	get_message() const;
		void		prep_to_send();

};