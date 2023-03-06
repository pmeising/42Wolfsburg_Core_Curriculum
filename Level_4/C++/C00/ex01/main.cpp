/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:10:20 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/23 13:42:03 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	user_input;
	int			i, j;

	i = 0;
	j = 0;
	while (true)
	{
		std::getline(std::cin, user_input);
		if (user_input == "EXIT")
			break;
		else if (user_input == "ADD")
		{
			PhoneBook.add(i % 8);
			i++;
		}
		else if (user_input == "SEARCH")
			PhoneBook.search();
		else if (j == 2)
		{
			std::cout << "Only accepted input: 'ADD', 'SEARCH', 'EXIT'. Try again.\n";
			j = 0;
		}
		else
			j++;
	}
	std::cout << "Thank you for using our new and improved PhoneBook system.\n";
}
