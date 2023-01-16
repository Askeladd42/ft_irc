/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:46:03 by plam              #+#    #+#             */
/*   Updated: 2023/01/16 14:31:34 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __USER_HPP__
# define __USER_HPP__

# include <iostream>
# include <vector>
# include <fcntl.h>

class User {
	protected:
		int					_fd;		// fd of the User
		int					_status;	// User's status
		std::string			_nickname;
		std::string			_username;
		std::string			_realname;
		std::string			_hostname;
		std::string			_hostaddr;
		//std::string		_buffer;	User's buffer, may change later

		User();
	private:
		User(const User &other);		//copy member function
		User				&operator=(const User &other);
	public:
		User(const int fd);
		virtual ~User();

		//setter member functions
		void				set_status(const int newStatus);
		void				set_nickname(const int newNick);
		void				set_username(const int newUser);
		void				set_realname(const int newReal);
		void				set_hostname(const int newHost);	//temporary, may bereplaced/deleted later
		void				set_hostaddr(const int newAddr);	//temporary, may bereplaced/deleted later

		//getter member functions
		int					get_fd() const;
		int					get_status() const;
		const std::string	&get_nickname() const;
		const std::string	&get_username() const;
		const std::string	&get_realname() const;
		const std::string	&get_hostname() const;
};

std::ostream				&operator<<(std::ostream &ost, const User &other);

#endif