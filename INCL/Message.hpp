/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:40:50 by plam              #+#    #+#             */
/*   Updated: 2023/03/07 16:21:20 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MESSAGE_HPP__
# define __MESSAGE_HPP__
# include "ft_irc.hpp"

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

		/* See Command.hpp to see how each of the message command treatment is done */

		void	cmd_to_msg(t_command *cmd);		// to see how to convert a correct msg command to a real commnd in the irc

};

#endif
