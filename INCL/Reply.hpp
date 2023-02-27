/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:32:30 by cmaginot          #+#    #+#             */
/*   Updated: 2023/02/26 16:23:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef REPLY_HPP
# define REPLY_HPP

# include <vector>
# include <string>
# include <cstring>
# include <iostream>
# include <sstream>

# include "../INCL/User.hpp"

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

#define NO_REPLY Reply(0, "")
#define RPL_WELCOME Reply(001, "<client> :Welcome to the <networkname> Network, <nick>[!<user>@<host>]")
#define RPL_YOURHOST Reply(002, "<client> :Your host is <servername>, running version <version>")
#define RPL_CREATED Reply(003, "<client> :This server was created <datetime>")
#define RPL_MYINFO Reply(004, "<client> <servername> <version> <available user modes> <available channel modes> [<channel modes with a parameter>]")
#define RPL_ISUPPORT Reply(005, "<client> <1-13 tokens> :are supported by this server")
#define RPL_BOUNCE Reply(010, "<client> <hostname> <port> :<info>")
#define RPL_STATSLINKINFO Reply(211, "")
#define RPL_STATSCOMMANDS Reply(212, "")
#define RPL_STATSCLINE Reply(213, "")
#define RPL_STATSILINE Reply(215, "")
#define RPL_STATSKLINE Reply(216, "")
#define RPL_ENDOFSTATS Reply(219, "")
#define RPL_UMODEIS Reply(221, "<client> <user modes>")
#define RPL_STATSLLINE Reply(241, "")
#define RPL_STATSUPTIME Reply(242, "")
#define RPL_STATSOLINE Reply(243, "")
#define RPL_STATSHLINE Reply(244, "")
#define RPL_LUSERCLIENT Reply(251, "<client> :There are <u> users and <i> invisible on <s> servers")
#define RPL_LUSEROP Reply(252, "<client> <ops> :operator(s) online"),
#define RPL_LUSERUNKNOWN Reply(253, "<client> <connections> :unknown connection(s)")
#define RPL_LUSERCHANNELS Reply(254, "<client> <channels> :channels formed")
#define RPL_LUSERME Reply(255, "<client> :I have <c> clients and <s> servers")
#define RPL_ADMINME Reply(256, "<client> [<server>] :Administrative info")
#define RPL_ADMINLOC1 Reply(257, "<client> :<info>")
#define RPL_ADMINLOC2 Reply(258, "<client> :<info>")
#define RPL_ADMINEMAIL Reply(259, "<client> :<info>")
#define RPL_TRYAGAIN Reply(263, "<client> <command> :Please wait a while and try again.")
#define RPL_LOCALUSERS Reply(265, "<client> [<u> <m>] :Current local users <u>, max <m>")
#define RPL_GLOBALUSERS Reply(266, "<client> [<u> <m>] :Current global users <u>, max <m>")
#define RPL_WHOISCERTFP Reply(276, "<nick> <client>:has client certificate fingerprint <fingerprint>")
#define RPL_NONE Reply(300, "")
#define RPL_AWAY Reply(301, "<client> <nick> :<message>")
#define RPL_USERHOST Reply(302, "<client> :[<reply>{ <reply>}]")
#define RPL_UNAWAY Reply(305, "<client> :You are no longer marked as being away")
#define RPL_NOWAWAY Reply(306, "<client> :You have been marked as being away")
#define RPL_WHOISREGNICK Reply(307, "<client> <nick> :has identified for this nick")
#define RPL_WHOISUSER Reply(311, "<nick> <client> <username> <hostname> * <realname>")
#define RPL_WHOISSERVER Reply(312, "<client> <nick> <server> :<server info>")
#define RPL_WHOISOPERATOR Reply(313, "<client> <nick> :is an IRC operator")
#define RPL_WHOWASUSER Reply(314, "<client> <nick> <username> <host> * :<realname>")
#define RPL_ENDOFWHO Reply(315, "<client> <mask> :End of WHO list")
#define RPL_WHOISIDLE Reply(317, "<client> <nick> <secs> <signon> :seconds idle, signon time")
#define RPL_ENDOFWHOIS Reply(318, "<client> <nick> :End of /WHOIS list")
#define RPL_WHOISCHANNELS Reply(319, "<client> <nick> :[prefix]<channel>{ [prefix]<channel>}")
#define RPL_WHOISSPECIAL Reply(320, "<client> <nick> :<message>")
#define RPL_LISTSTART Reply(321, "<client> Channel :Users  Name")
#define RPL_LIST Reply(322, "<client> <channel> <client count> :<topic>")
#define RPL_LISTEND Reply(323, "<client> :End of /LIST")
#define RPL_CHANNELMODEIS Reply(324, "<client> <channel> <modestring> <mode arguments>...")
#define RPL_CREATIONTIME Reply(329, "<client> <channel> <creationtime>")
#define RPL_WHOISACCOUNT Reply(330, "<client> <nick> <account> :is logged in as")
#define RPL_NOTOPIC Reply(331, "<client> <channel> :No topic is set")
#define RPL_TOPIC Reply(332, "<client> <channel> :<topic>")
#define RPL_TOPICWHOTIME Reply(333, "<client> <channel> <nick> <setat>")
#define RPL_INVITELIST Reply(336, "<client> <channel>")
#define RPL_ENDOFINVITELIST Reply(337, "<client> :End of /INVITE list")
#define RPL_WHOISACTUALLY Reply(338, "<client> <nick> <username>@<hostname> <ip> :Is actually using host")
#define RPL_INVITING Reply(341, "<client> <nick> <channel>")
#define RPL_INVEXLIST Reply(346, "<client> <channel> <mask>")
#define RPL_ENDOFINVEXLIST Reply(347, "<client> <channel> :End of Channel Invite Exception List")
#define RPL_EXCEPTLIST Reply(348, "<client> <channel> <mask>")
#define RPL_ENDOFEXCEPTLIST Reply(349, "<client> <channel> :End of channel exception list")
#define RPL_VERSION Reply(351, "<client> <version> <server> :<comments>")
#define RPL_WHOREPLY Reply(352, "<client> <channel> <username> <host> <server> <nick> <flags> :<hopcount> <realname>"),
#define RPL_NAMREPLY Reply(353, "<client> <symbol> <channel> :[prefix]<nick>{ [prefix]<nick>}")
#define RPL_LINKS Reply(364, "<client> * <server> :<hopcount> <server info>")
#define RPL_ENDOFLINKS Reply(365, "<client> * :End of /LINKS list")
#define RPL_ENDOFNAMES Reply(366, "<client> <channel> :End of /NAMES list")
#define RPL_BANLIST Reply(367, "<client> <channel> <mask> [<who> <set-ts>]")
#define RPL_ENDOFBANLIST Reply(368, "<client> <channel> :End of channel ban list")
#define RPL_ENDOFWHOWAS Reply(369, "<client> <nick> :End of WHOWAS")
#define RPL_INFO Reply(371, "<client> :<string>")
#define RPL_MOTD Reply(372, "<client> :<line of the motd>")
#define RPL_ENDOFINFO Reply(374, "<client> :End of INFO list")
#define RPL_MOTDSTART Reply(375, "<client> :- <server> Message of the day - ")
#define RPL_ENDOFMOTD Reply(376, "<client> :End of /MOTD command")
#define RPL_WHOISHOST Reply(378, "<client> <nick> :is connecting from *@localhost 127.0.0.1")
#define RPL_WHOISMODES Reply(379, "<client> <nick> :is using modes +ailosw")
#define RPL_YOUREOPER Reply(381, "<client> :You are now an IRC operator")
#define RPL_REHASHING Reply(382, "<client> <config file> :Rehashing")
#define RPL_TIME Reply(391, "<client> <server> [<timestamp> [<TS offset>]] :<human-readable time>")
#define ERR_UNKNOWNERROR Reply(400, "<client> <command>{ <subcommand>} :<info>")
#define ERR_NOSUCHNICK Reply(401, "<client> <nickname> :No such nick/channel")
#define ERR_NOSUCHSERVER Reply(402, "<client> <server name> :No such server")
#define ERR_NOSUCHCHANNEL Reply(403, "<client> <channel> :No such channel")
#define ERR_CANNOTSENDTOCHAN Reply(404, "<client> <channel> :Cannot send to channel")
#define ERR_TOOMANYCHANNELS Reply(405, "<client> <channel> :You have joined too many channels")
#define ERR_WASNOSUCHNICK Reply(406, "<client> :There was no such nickname")
#define ERR_NOORIGIN Reply(409, "<client> :No origin specified")
#define ERR_NORECIPIENT Reply(411, "")
#define ERR_NOTEXTTOSEND Reply(412, "")
#define ERR_NOTOPLEVEL Reply(413, "")
#define ERR_WILDTOPLEVEL Reply(414, "")
#define ERR_INPUTTOOLONG Reply(417, "<client> :Input line was too long")
#define ERR_UNKNOWNCOMMAND Reply(421, "<client> <command> :Unknown command")
#define ERR_NOMOTD Reply(422, "<client> :MOTD File is missing")
#define ERR_NONICKNAMEGIVEN Reply(431, "<client> :No Nickname Given")
#define ERR_ERRONEUSNICKNAME Reply(432, "<client> <nick> :Erroneus nickname")
#define ERR_NICKNAMEINUSE Reply(433, "<client> <nick> :Nickname is already in use")
#define ERR_NICKCOLLISION Reply(436, "<client> <nick> :Nickname collision")
#define ERR_USERNOTINCHANNEL Reply(441, "<client> <nick> <channel> :They aren't on that channel")
#define ERR_NOTONCHANNEL Reply(442, "<client> <channel> :You're not on that channel")
#define ERR_USERONCHANNEL Reply(443, "<client> <nick> <channel> :is already on channel")
#define ERR_NOTREGISTERED Reply(451, "<client> :You have not registered")
#define ERR_NEEDMOREPARAMS Reply(461, "<client> <command> :Not enough parameters")
#define ERR_ALREADYREGISTERED Reply(462, "<client> :You may not reregister")
#define ERR_PASSWDMISMATCH Reply(464, "<client> :Password incorrect")
#define ERR_YOUREBANNEDCREEP Reply(465, "<client> :You are banned from this server.")
#define ERR_CHANNELISFULL Reply(471, "<client> <channel> :Cannot join channel (+l)")
#define ERR_UNKNOWNMODE Reply(472, "<client> <modechar> :is unknown mode char to me")
#define ERR_INVITEONLYCHAN Reply(473, "<client> <channel> :Cannot join channel (+i)")
#define ERR_BANNEDFROMCHAN Reply(474, "<client> <channel> :Cannot join channel (+b)")
#define ERR_BADCHANNELKEY Reply(475, "<client> <channel> :Cannot join channel (+k)")
#define ERR_BADCHANMASK Reply(476, "<channel> :Bad Channel Mask")
#define ERR_NOPRIVILEGES Reply(481, "<client> :Permission denied - You are not an IRC operator")
#define ERR_CHANOPRIVSNEEDED Reply(482, "<client> <channel> :You're not channel operator")
#define ERR_CANTKILLSERVER Reply(483, "<client> :You cant kill a server!")
#define ERR_NOOPERHOST Reply(491, "<client> :No O-lines for your host")
#define ERR_UMODEUNKNOWNFLAG Reply(501, "<client> :Unknown MODE flag")
#define ERR_USERSDONTMATCH Reply(502, "<client> :Cant change mode for other users")
#define ERR_HELPNOTFOUND Reply(524, "<client> <subject> :No help available on this topic")
#define ERR_INVALIDKEY Reply(525, "<client> <target chan> :Key is not well-formed")
#define RPL_STARTTLS Reply(670, "<client> :STARTTLS successful, proceed with TLS handshake")
#define RPL_WHOISSECURE Reply(671, "<client> <nick> :is using a secure connection")
#define ERR_STARTTLS Reply(691, "<client> :STARTTLS failed (Wrong moon phase)")
#define ERR_INVALIDMODEPARAM Reply(696, "<client> <target chan/user> <mode char> <parameter> :<description>")
#define RPL_HELPSTART Reply(704, "<client> <subject> :<first line of help section>")
#define RPL_HELPTXT Reply(705, "<client> <subject> :<line of help text>")
#define RPL_ENDOFHELP Reply(706, "<client> <subject> :<last line of help text>")
#define ERR_NOPRIVS Reply(723, "<client> <priv> :Insufficient oper privileges.")
#define RPL_LOGGEDIN Reply(900, "<client> <nick>!<user>@<host> <account> :You are now logged in as <username>")
#define RPL_LOGGEDOUT Reply(901, "<client> <nick>!<user>@<host> :You are now logged out")
#define ERR_NICKLOCKED Reply(902, "<client> :You must use a nick assigned to you")
#define RPL_SASLSUCCESS Reply(903, "<client> :SASL authentication successful")
#define ERR_SASLFAIL Reply(904, "<client> :SASL authentication failed")
#define ERR_SASLTOOLONG Reply(905, "<client> :SASL message too long")
#define ERR_SASLABORTED Reply(906, "<client> :SASL authentication aborted")
#define ERR_SASLALREADY Reply(907, "<client> :You have already authenticated using SASL")
#define RPL_SASLMECHS Reply(908, "<client> <mechanisms> :are available SASL mechanisms")





#define ERR_TOKENMISMATCH Reply(0, "<client> :token incorrect")
#define RPL_PONG Reply(0, "")

# endif