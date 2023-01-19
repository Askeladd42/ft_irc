/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:40:50 by plam              #+#    #+#             */
/*   Updated: 2023/01/19 15:47:18 by plam             ###   ########.fr       */
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
};

#endif