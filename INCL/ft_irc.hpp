/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercore <mmercore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:24:09 by mmercore          #+#    #+#             */
/*   Updated: 2023/01/11 18:44:00 by mmercore         ###   ########.fr       */
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

# include <unistd.h>			/*unistd		=>		lseek,fstat,fcntl	  */
# include <poll.h>				/*poll			=>		poll				  */

# include "Client.hpp"			/* class Client header/template file */
# include "Channel.hpp"			/* class Channel header/template file */
//		DEFINES
# define PRINT	std::cout <<
# define ENDL	<< std::endl

//# define DEFINE	# define // Ne marche pas, se renseigner pk

//		TYPEDEFS
typedef std::string		str;

//		CLASSES & TEMPLATES
# include "Server.hpp"

# endif

//		PROTOTYPES