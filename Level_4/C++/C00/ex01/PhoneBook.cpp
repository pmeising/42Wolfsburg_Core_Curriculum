/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:12:12 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/23 13:45:11 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	Contact	one, two, three, four, five, six, seven, eight;

	std::cout << "Initiating 8 instances of the Contact object.\n";
	Contacts[0] = one;
	Contacts[1] = two;
	Contacts[2] = three;
	Contacts[3] = four;
	Contacts[4] = five;
	Contacts[5] = six;
	Contacts[6] = seven;
	Contacts[7] = eight;
	std::cout << "Stored the Contacts in my private Contacts array.\n";
}

void	PhoneBook::add(int i)
{
	std::string	input, fn, ln, nn, pn, ds;

	// Prompt user contact data. fn = first name etc.
	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Invalid input.\n";
		return;
	}
	else
		fn = input;
	
	// Same for last name:
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Invalid input.\n";
		return;
	}
	else
		ln = input;

	// Same for nickname:
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Invalid input.\n";
		return;
	}
	else
		nn = input;

	// Same for phone number:
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Invalid input.\n";
		return;
	}
	else
		pn = input;

	// Same for darkest secret:
	std::cout << "Psst... ... Tell us their 'Darkest secret': ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Invalid input.\n" << "That won't do for blackmail...\n";
		return;
	}
	else
		ds = input;

	if (Contacts[i].set_info(fn, ln, nn, pn, ds) == 1)
		std::cout << "Invalid input, couldn't save contact.\n";
	else
		std::cout << "Contact added successfully!\n";
}

void	PhoneBook::search()
{
	int	i = 0;
	int	j = -1;
	std::string	input = "TEMPORARY";

	std::cout << "     Index | First name |  Last name |   nickname" << std::endl;
	while (true)
	{
		search_short(i);
		i++;
		if (i == 8)
			break;
	}
	std::cout << "Which contact would you like to see in detail?\n";
	while (true)
	{
		std::getline(std::cin, input);
		j = input[0] - 48;
		if (j >= 1 && j <= 8 && input.length() == 1)
		{
			search(j - 1);
			return;
		}
		else
			std::cout << "Invalid index, please try again.\n";
	}
	return;
}

void	PhoneBook::str_adjust_less(std::string str)
{
	std::string	new_str;
	int	len = str.length();
	int	lenght = 10;
	int	buffer = lenght - len;

	while (buffer > 0)
	{
		std::cout << " ";
		buffer--;
	}
}

void	PhoneBook::str_adjust_more(std::string str)
{
	int	i = 0;

	while (i < 9)
	{
		std::cout << str[i];
		i++;
	}
	std::cout << ".";
}

void	PhoneBook::search_short(int i)
{
	std::cout << "         " << i + 1 << " | ";
	if (Contacts[i].get_info("firstName").length() < 10)
	{
		str_adjust_less(Contacts[i].get_info("firstName"));
		std::cout << Contacts[i].get_info("firstName") << " | ";
	}
	else if (Contacts[i].get_info("firstName").length() > 10)
	{
		str_adjust_more(Contacts[i].get_info("firstName"));
		std::cout << " | ";
	}
	else
		std::cout << Contacts[i].get_info("firstName") << " | ";
	if (Contacts[i].get_info("lastName").length() < 10)
	{
		str_adjust_less(Contacts[i].get_info("lastName"));
		std::cout << Contacts[i].get_info("lastName") << " | ";
	}
	else if (Contacts[i].get_info("lastName").length() > 10)
	{
		str_adjust_more(Contacts[i].get_info("lastName"));
		std::cout << " | ";
	}
	else
		std::cout << Contacts[i].get_info("lastName") << " | ";
	
	if (Contacts[i].get_info("nickName").length() < 10)
	{
		str_adjust_less(Contacts[i].get_info("nickName"));
		std::cout << Contacts[i].get_info("nickName") << " | ";
	}
	else if (Contacts[i].get_info("nickName").length() > 10)
	{
		str_adjust_more(Contacts[i].get_info("nickName"));
		std::cout << " | ";
	}
	else
		std::cout << Contacts[i].get_info("nickName");
	std::cout << std::endl;
}

void	PhoneBook::search(int i)
{
	std::cout << "First Name: " << Contacts[i].get_info("firstName") << std::endl;
	std::cout << "Last Name: " << Contacts[i].get_info("lastName") << std::endl;
	std::cout << "Nickname: " << Contacts[i].get_info("nickName") << std::endl;
	std::cout << "Phone number: " << Contacts[i].get_info("phoneNumber") << std::endl;
	std::cout << "Darkest Secret: " << Contacts[i].get_info("darkestSecret") << std::endl;
}
