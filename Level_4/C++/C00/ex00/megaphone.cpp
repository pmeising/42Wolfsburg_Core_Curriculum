/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:10:22 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/20 12:55:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	// std::cout -> Standard Character Output
	// The std:: acts like a library, which is called using the '::'
	// std::string Test = "this is fun\n";
	int	i = 1;
	int	j = 0;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc > 1)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << (char)std::toupper(argv[i][j]);
				j++;	
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
