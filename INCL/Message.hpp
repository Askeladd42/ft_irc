/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:40:50 by plam              #+#    #+#             */
/*   Updated: 2023/01/17 17:58:34 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MESSAGES_HPP__
# define __MESSAGES_HPP__

# include "User.hpp"
# include "Server.hpp"

class Message {
	private:
		 
	public:
		Message();
		~Message();
		Message(const Message &other);
		&operator=(const Message &other);
};

#endif