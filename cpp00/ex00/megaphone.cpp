/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:16:12 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/08/07 12:33:14 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printToupperString(std::string str)
{
	int					i;
	unsigned char		c;
	
	i = 0;
	while(str[i])
	{
		c = std::toupper(str[i]);
		std::cout << c;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int			i;
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			str = (std::string)argv[i];
			printToupperString(str);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
