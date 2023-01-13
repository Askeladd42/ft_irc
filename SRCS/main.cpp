/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:26:22 by mmercore          #+#    #+#             */
/*   Updated: 2023/01/13 11:50:55 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/ft_irc.hpp"

/* poll() reference source : http://manpagesfr.free.fr/man/man2/poll.2.html */


int	main(int ac, char **av, char **envp) {
	(void)ac, (void)av, (void)envp;
	struct pollfd	fds[1];
	fds[0].fd = 0;
	fds[0].events = POLLIN;

	while (true) {
		int	ret = poll(fds, 1, -1);
		if	(ret == -1) {
			std::cerr << "poll() error" << std::endl;
			return 1;
		}
		if (fds[0].revents & POLLIN) {
			char	buf[1024];
			std::cin.getline(buf, sizeof(buf));
			std::cout << "input: " << buf << std::endl;
		}
	}
	return (0);
}