/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:51:43 by plam              #+#    #+#             */
/*   Updated: 2023/03/16 16:15:41 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHANNEL_HPP__
# define __CHANNEL_HPP__
# include "ft_irc.hpp"

class Channel {
	private:
		std::vector<User *>	_ch_usr_list;
	protected:
		std::string	_name;
	public:
		Channel();
		Channel(const Channel &other);
		~Channel();
		Channel	&operator=(const Channel &other);

		void	add(User &user);
		void	del(User &user);
};

#endif