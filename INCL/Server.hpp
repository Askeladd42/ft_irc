/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercore <mmercore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:40:58 by mmercore          #+#    #+#             */
/*   Updated: 2023/01/16 15:26:39 by mmercore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __server_HPP__
# define __server_HPP__

# include "ft_irc.hpp"

// Eventuellement il faudra bouger ces defines vers un fichier de conf
// Par securite
# define DEFAULT_PORT 1111
# define DEFAULT_PWD "abc"

typedef struct	e_sock_conf {
	int	domain;
	int	type;
	int	protocol;
}				t_sock_conf;

typedef enum e_serv_error {
	nothing = 0,
	syscall_fail,
	socket_fail
}							t_serv_error;

// 	Domain:
// Pour l'instant AF_LOCAL (alias pour AF_UNIX)
// Pour le vrai projet il faudra passer sur AF_INET (IPV4)
// >man socket
//	Type:
// Pour l'instant SOCK_STREAM
// J'ai [as trop test les autres]
//	Protocol:
// Il n'y a qu'un type de protocol pour SOCK_STREAM
// 0 le choisit par defaut
# define	DEFAULT_SC	(t_sock_conf){\
	.domain=AF_LOCAL,\
	.type=SOCK_STREAM,\
	.protocol=0}

class Server {
		// Attribut public: La classe a t'elle rencontre
		// Un pb ?
		t_serv_error	errval = 0;

		Server(int port=DEFAULT_PORT, std::string password=DEFAULT_PWD, t_sock_conf sock_conf=DEFAULT_SC);
		~Server();

		std::string	get_password() const;
		void		set_password(std::string password=DEFAULT_PWD);

		int			get_port() const;
		void		set_port(int port=DEFAULT_PORT);
		
		int			get_socketfd() const;
		void		set_socketfd(int socketfd=-1, t_sock_conf sock_conf=DEFAULT_SC);
	private:
		std::string	_password;
		int			_port;
		int			_socketfd;
};

#endif