/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:46:03 by plam              #+#    #+#             */
/*   Updated: 2023/01/13 13:35:51 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLIENT_HPP__
# define __CLIENT_HPP__

# include <iostream>
# include <vector>
# include <fcntl.h>

class Client {
	protected:
		int					_fd;		// fd of the client
		int					_status;	// client's status
		std::string			_nickname;
		std::string			_username;
		std::string			_realname;
		std::string			_hostname;
		std::string			_hostaddr;
		//std::string		_buffer;	client's buffer, may change later

		Client();
	private:
		Client(const Client &other);		//copy member function
		Client				&operator=(const Client &other);
	public:
		Client(const int fd);
		virtual ~Client();

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

std::ostream				&operator<<(std::ostream &ost, const Client &other);

#endif