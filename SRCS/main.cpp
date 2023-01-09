/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercore <mmercore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:26:22 by mmercore          #+#    #+#             */
/*   Updated: 2023/01/07 18:40:34 by mmercore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/ft_irc.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	str	a = "everyone"; // Notez le typedef
	PRINT "Hello " << a ENDL; // Notez les defines
	return (0);
}