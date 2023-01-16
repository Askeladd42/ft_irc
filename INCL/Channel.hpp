/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:51:43 by plam              #+#    #+#             */
/*   Updated: 2023/01/16 14:30:50 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHANNEL_HPP__
# define __CHANNEL_HPP__
# include "User.hpp"

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

		void	add(User &user);
		void	del(User &user);
};

#endif