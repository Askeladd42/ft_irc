/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercore <mmercore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:40:58 by mmercore          #+#    #+#             */
/*   Updated: 2023/01/30 16:31:26 by mmercore         ###   ########.fr       */
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
//	void		socket_params;
	int			domain;
	int			type;
	int			protocol;
//	void		socket_opts;
	int			level;
	int			optname;
	int			optvalobj;
	const void *optval;
	socklen_t	optlen;
}				t_sock_conf;

typedef enum e_serv_error {
	nothing = 0,
	syscall_fail,
	socket_fail,
	sock_opt_fail
}							t_serv_error;

// 		Domain:
// Pour l'instant AF_LOCAL (alias pour AF_UNIX)
// Pour le vrai projet il faudra passer sur AF_INET (IPV4)
// >man socket
//		Type:
// Pour l'instant SOCK_STREAM
// J'ai [as trop test les autres]
//		Protocol:
// Il n'y a qu'un type de protocol pour SOCK_STREAM
// 0 le choisit par defaut

//		Level:
// Specifie comme SOL_SOCKET selon la dock.
// Si on veut set des options pour des protocoles
// En particulier il faudra trouver leur level avec getprotoent
//		Optname:
// On set SO_REUSEADDR et SO_REUSEPORT
// Le premier permet de reutiliser la meme addr/port en cas de pb
// Pourquoi ? Si le pb crashem la socket va rentrer
// Dans un state appele TIME_WAIT ou elle va attendre
// Que tous les packets soient arrives a leur destination,
// Si on relance le programme elle ne sera pas utilisable
// Avec cette option, si. 
// Le deuxieme permet a plusieures socket de bind
// Avec la meme addresse/port
//		Optval:
// Doit etre un pointeur sur un int qui allume ou eteint l'option
//		Optlen:
// La len de ce que pointe opval

# define	DEFAULT_SC	(t_sock_conf){		\
	.domain=AF_LOCAL,						\
	.type=SOCK_STREAM,						\
	.protocol=0,							\
	.level=SOL_SOCKET,						\
	.optname=SO_REUSEADDR | SO_REUSEPORT,	\
	.optvalobj=1,							\
	.optval=(const void *)(sizeof(t_sock_conf) - sizeof(socklen_t) - sizeof(const void *)),				\
	.optlen=sizeof(int)			\
	}

class Server {
	public:
		// Attribut public: La classe a t'elle rencontre
		// Un pb ?
		t_serv_error	errval = nothing;

		Server(int port=DEFAULT_PORT, str password=DEFAULT_PWD, t_sock_conf sock_conf=DEFAULT_SC);
		~Server();

		std::string	get_password() const;
		void		set_password(std::string password=DEFAULT_PWD);

		int			get_port() const;
		void		set_port(int port=DEFAULT_PORT);
		
		int			get_socketfd() const;
		void		set_socketfd(int socketfd=-1, t_sock_conf sock_conf=DEFAULT_SC);

		int			set_sockopt(int level, int optname, const void *optval, socklen_t optlen);
	private:
		std::string	_password;
		int			_port;
		int			_socketfd;

		//https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
		// Equivalent a struct sockaddr* en cast, supporte plus d'implementations
		struct sockaddr_in	address;
};

#endif