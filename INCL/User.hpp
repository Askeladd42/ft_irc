/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:46:03 by plam              #+#    #+#             */
/*   Updated: 2023/03/07 16:20:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __USER_HPP__
# define __USER_HPP__

# include <iostream>
# include <vector>
# include <fcntl.h>

#define USR_STAT_BAN -2
#define USR_STAT_REGISTERED 1

class User
{
	private:
		User();
		User(const User &other);		//copy member function
		User				&operator=(const User &other);

	protected:
		int					_fd;		// fd of the User
		int					_status;	// User's status
		bool				_connected; // if user give the password
		std::string			_nickname;
		std::string			_username;
		std::string			_realname;
		std::string			_hostname;
		std::string			_hostaddr;
		//std::string		_buffer;	User's buffer, may change later
		//std::string		_ping_pong_token;

	public:
		User(const int fd);
		virtual ~User();

		//setter member functions
		void				set_status(const int newStatus);
		void				set_connected();
		void				set_disconnected();
		void				set_user_admin();
		void				set_user_normal();
		void				set_nickname(const std::string newNick);
		void				set_username(const std::string newUser);
		void				set_realname(const std::string newReal);
		void				set_hostname(const std::string newHost);	//temporary, may be replaced/deleted later
		void				set_hostaddr(const std::string newAddr);	//temporary, may be replaced/deleted later

		//getter member functions
		int					get_fd() const;
		int					get_status() const;
		bool				get_connected() const;
		const std::string	&get_nickname() const;
		const std::string	&get_username() const;
		const std::string	&get_realname() const;
		const std::string	&get_hostname() const;
		const std::string	&get_hostaddr() const;
};

std::ostream				&operator<<(std::ostream &ost, const User &other);

#endif
