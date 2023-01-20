/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:40:50 by plam              #+#    #+#             */
/*   Updated: 2023/01/20 15:37:40 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MESSAGE_HPP__
# define __MESSAGE_HPP__

# include "User.hpp"
# include "Server.hpp"

class Message {
	private:
		 
	public:
		Message();
		~Message();
		Message(const Message &other);
		Message	&operator=(const Message &other);
		
		void	SendPvtMess(User Usr1, User Usr2, std::string Mess);	// sending private message from a user to another ?
		void	SendCnlMess(User Usr, Channel Cnl, std::string Mess);	// sending message in/to a channel ?

		/*	An IRC message is a single line, delimited by a pair of CR ('\r', 0x0D) and LF ('\n', 0x0A) characters.
		**
		**	When reading messages from a stream, read the incoming data into a buffer.
		**	Only parse and process a message once you encounter the \r\n at the end of it.
		**	If you encounter an empty message, silently ignore it.
		**	When sending messages, ensure that a pair of \r\n characters follows every single message your software sends out.
		**	Messages have this format, as rough ABNF:
		**
		**	message	::= ['@' <tags> SPACE] [':' <source> SPACE] <command> <parameters> <crlf>
		**	SPACE	::=  %x20 *( %x20 )	; space character(s)
		**	crlf	::=  %x0D %x0A		; "carriage return" "linefeed"
		**
		**	The specific parts of an IRC message are:
		**
		**	- tags: Optional metadata on a message, starting with ('@', 0x40).
		**	- source: Optional note of where the message came from, starting with (':', 0x3A).
		**	- command: The specific command this message represents.
		**	- parameters: If it exists, data relevant to this specific command.
		**	These message parts, and parameters themselves, are separated by one or more ASCII SPACE characters (' ', 0x20).
		**
		**	Most IRC servers limit messages to 512 bytes in length, including the trailing CR-LF characters.
		**	Implementations which include message tags need to allow additional bytes for the tags section of a message;
		**	clients must allow 8191 additional bytes and servers must allow 4096 additional bytes.
		*/

		void	Ping(Token &tkn);	// temporary adding them here, need more development before fully implementation
		/*
		** The PING command is sent by either clients or servers to check the other side of the connection is still connected and/or to check for connection latency, at the application layer.

		** The <token> may be any non-empty string.

		** When receiving a PING message, clients or servers must reply to it with a PONG message with the same <token> value. This allows either to match PONG with the PING they reply to, for example to compute latency.

		** Clients should not send PING during connection registration, though servers may accept it. Servers may send PING during connection registration and clients must reply to them.

		** Older versions of the protocol gave specific semantics to the <token> and allowed an extra parameter; but these features are not consistently implemented and should not be relied on. Instead, the <token> should be treated as an opaque value by the receiver.

		** Numeric Replies:
		** - ERR_NEEDMOREPARAMS (461)
		** - ERR_NOORIGIN (409)
		** - Deprecated Numeric Reply: ERR_NOSUCHSERVER (402)
		*/

		void	Pong(Token &tkn, Server &svr);	// temporary adding them here, need more development before fully implementation
		/*	Command: PONG
		**	Parameters: [<server>] <token>
		**	The PONG command is used as a reply to PING commands, by both clients and servers. The <token> should be the same as the one in the PING message that triggered this PONG.

		**	Servers MUST send a <server> parameter, and clients SHOULD ignore it. It exists for historical reasons, and indicates the name of the server sending the PONG. Clients MUST NOT send a <server> parameter.
		*/

		/*to do :
		- CAP message :
			Command: CAP
			Parameters: <subcommand> [:<capabilities>]
			The CAP command is used for capability negotiation between a server and a client.

			The CAP message may be sent from the server to the client.

		- AUTHENTICATE message :
			Command: AUTHENTICATE
			The AUTHENTICATE command is used for SASL authentication between a server and a client.
			The client must support and successfully negotiate the "sasl" client capability (as listed below in the SASL specifications) before using this command.

			The AUTHENTICATE message may be sent from the server to the client.
		
		- PASS message :
			Command: PASS
			Parameters: <password>
			The PASS command is used to set a ‘connection password’.
			If set, the password must be set before any attempt to register the connection is made.
			This requires that clients send a PASS command before sending the NICK / USER combination.

			The password supplied must match the one defined in the server configuration.
			It is possible to send multiple PASS commands before registering but only the last one sent
			is used for verification and it may not be changed once the client has been registered.

			If the password supplied does not match the password expected by the server,
			then the server SHOULD send ERR_PASSWDMISMATCH (464) and MAY then close the connection with ERROR.
			Servers MUST send at least one of these two messages.

			Servers may also consider requiring SASL authentication upon connection as an alternative to this,
			when more information or an alternate form of identity verification is desired.

			Numeric replies:
			- ERR_NEEDMOREPARAMS (461)
			- ERR_ALREADYREGISTERED (462)
			- ERR_PASSWDMISMATCH (464)

			ex : PASS secretpasswordhere

			- NICK message:
				Command: NICK
				Parameters: <nickname>
				The NICK command is used to give the client a nickname or change the previous one.

				If the server receives a NICK command from a client where the desired nickname is already in use on the network, it should issue an ERR_NICKNAMEINUSE numeric and ignore the NICK command.

				If the server does not accept the new nickname supplied by the client as valid (for instance, due to containing invalid characters), it should issue an ERR_ERRONEUSNICKNAME numeric and ignore the NICK command.

				If the server does not receive the <nickname> parameter with the NICK command, it should issue an ERR_NONICKNAMEGIVEN numeric and ignore the NICK command.

				The NICK message may be sent from the server to clients to acknowledge their NICK command was successful, and to inform other clients about the change of nickname. In these cases, the <source> of the message will be the old nickname [ [ "!" user ] "@" host ] of the user who is changing their nickname.

				Numeric Replies:
				- ERR_NONICKNAMEGIVEN (431)
				- ERR_ERRONEUSNICKNAME (432)
				- ERR_NICKNAMEINUSE (433)
				- ERR_NICKCOLLISION (436)

				ex : NICK Wiz						; Requesting the new nick "Wiz".
					 :WiZ NICK Kilroy				; WiZ changed his nickname to Kilroy.
					 :dan-!d@localhost NICK Mamoped	; dan- changed his nickname to Mamoped.
				
				- USER message
					Command: USER
					Parameters: <username> 0 * <realname>
					The USER command is used at the beginning of a connection to specify the username and realname of a new user.

					It must be noted that <realname> must be the last parameter because it may contain SPACE (' ', 0x20) characters,
					and should be prefixed with a colon (:) if required.

					Servers MAY use the Ident Protocol to look up the ‘real username’ of clients.
					If username lookups are enabled and a client does not have an Identity Server enabled,
					the username provided by the client SHOULD be prefixed by a tilde ('~', 0x7E) to show that this value is user-set.

					The maximum length of <username> may be specified by the USERLEN RPL_ISUPPORT parameter.
					If this length is advertised, the username MUST be silently truncated to the given length before being used.
					The minimum length of <username> is 1, ie. it MUST NOT be empty.
					If it is empty, the server SHOULD reject the command with ERR_NEEDMOREPARAMS (even if an empty parameter is provided);
					otherwise it MUST use a default value instead.

					The second and third parameters of this command SHOULD be sent as one zero ('0', 0x30) and one asterisk character ('*', 0x2A) by the client,
					as the meaning of these two parameters varies between different versions of the IRC protocol.

					Clients SHOULD use the nickname as a fallback value for <username> and <realname> when they don’t have a meaningful value to use.

					If a client tries to send the USER command after they have already completed registration with the server,
					the ERR_ALREADYREGISTERED reply should be sent and the attempt should fail.

					If the client sends a USER command after the server has successfully received a username using the Ident Protocol,
					the <username> parameter from this command should be ignored in favour of the one received from the identity server.

					Numeric Replies:
					- ERR_NEEDMOREPARAMS (461)
					- ERR_ALREADYREGISTERED (462)


		*/

};

#endif