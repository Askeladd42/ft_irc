/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:24:09 by mmercore          #+#    #+#             */
/*   Updated: 2023/03/07 16:21:16 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_H
# define IRC_H

//		LIBRARIES
# include <iostream>			/*iostream		=>		std::cout <<...		  */
# include <sys/types.h>			/*types			=>		socket...			  */
# include <sys/socket.h>		/*socket									  */
# include <netdb.h>				/*netdb			=>		getprotobyname...	  */
# include <arpa/inet.h>			/*arpa			=>		htons()/htonl...	  */
# include <netinet/in.h>		/*in			=>  	inet_addr...		  */
# include <signal.h>			/*signal		=>		signal			  	  */
# include <vector>
# include <string>
# include <cstring>

# include <unistd.h>			/*unistd		=>		lseek,fstat,fcntl	  */
# include <poll.h>				/*poll			=>		poll				  */

#include <netinet/in.h>			/*netinet/in	=>		pour sockaddr_in	  */

#include <cstddef>				/*cstddef		=>		std::size_t...		  */

//		DEFINES
# define PRINT	std::cout <<
# define PRERR	std::cerr <<
# define ENDL	<< std::endl;
//# define DEFINE	# define // Ne marche pas, se renseigner pk

//		TYPEDEFS
typedef std::string		str;
typedef std::size_t		size_t;

//		CLASSES & TEMPLATES
# include "Reply.hpp"			/* class Client header/template file */
# include "User.hpp"			/* class Client header/template file */
# include "Command.hpp"			/* class Client header/template file */
# include "Server.hpp"
// # include "Channel.hpp"			/* class Channel header/template file */
// # include "Message.hpp"			/* class Client header/template file */

//		FUNCTIONS & MACROS

//		PROTOTYPES
void	ft_memset(void *a, char c, size_t l);
void	ft_bzero(void *a, size_t l = 0);

# endif
