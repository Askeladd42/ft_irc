/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:26:22 by mmercore          #+#    #+#             */
/*   Updated: 2023/01/11 12:51:30 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/ft_irc.hpp"

int	main(int ac, char **av, char **envp) {
	struct pollfd fds[1];
	fds[0].fd = 0;
	fds[0].events = POLLIN;

	while (true) {
		int	ret = poll(fds, 1, -1);
		if	(ret == -1) {
			std::cerr << "poll() error" << std::endl;
			return 1;
		}
		if (fds[0].revents & POLLIN) {
			char buf[1024];
			std::cin.getline(buf, sizeof(buf));
			std::cout << "input: " << buf << std::endl;
		}
	}
	return (0);
}