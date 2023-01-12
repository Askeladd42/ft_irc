/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:51:43 by plam              #+#    #+#             */
/*   Updated: 2023/01/12 16:30:01 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHANNEL_HPP__
# define __CHANNEL_HPP__
# include "Client.hpp"

class Channel {
	private:
		/* data */
	protected:
		/* data */
	public:
		Channel();
		Channel(const Channel &other);
		~Channel();
		Channel	&operator=(const Channel &other);

		void	add(Client &user);
		void	del(Client &user);
};

#endif