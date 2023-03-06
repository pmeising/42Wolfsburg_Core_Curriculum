/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:44:57 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/23 10:35:06 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
// #include <cstdlib>

// void	ft_add_user(PhoneBook PhoneBook, int i)
// {
// 	std::string	user_input;

// 	// std::cout << "Please add the information in the prompted order. Missing values can not be accepted.\n";
// 	std::cout << "First name: ";
// 	std::getline(std::cin, user_input);
// 	if (user_input.length() > 0)
// 	else
// 	{
// 		std::cout << "Invalid input. No empty fields allowed." << std::endl;
// 		return;
// 	}
// 	std::cout << "Last name: ";
// 	std::getline(std::cin, user_input);
// 	if (user_input.length() > 0)
// 		PhoneBook.Contacts[i].last_name = user_input;
// 	else
// 	{
// 		std::cout << "Invalid input. No empty fields allowed." << std::endl;
// 		return;
// 	}
// 	std::cout << "Nickname: ";
// 	std::getline(std::cin, user_input);
// 	if (user_input.length() > 0)
// 		PhoneBook.Contacts[i].nickname = user_input;
// 	else
// 	{
// 		std::cout << "Invalid input. No empty fields allowed." << std::endl;
// 		return;
// 	}
// 	std::cout << "Phone number: ";
// 	std::getline(std::cin, user_input);
// 	if (user_input.length() > 0)
// 		PhoneBook.Contacts[i].phone_number = user_input;
// 	else
// 	{
// 		std::cout << "Invalid input. No empty fields allowed." << std::endl;
// 		return;
// 	}
// 	std::cout << "Darkest secret: ";
// 	std::getline(std::cin, user_input);
// 	if (user_input.length() > 0)
// 		PhoneBook.Contacts[i].darkest_secret = user_input;
// 	else
// 	{
// 		std::cout << "Invalid input. No empty fields allowed." << std::endl;
// 		return;
// 	}
// 	std::cout << "Adding...\n";
// 	std::cout << "Thanks! You have added Contact: '" << PhoneBook.Contacts[i].first_name << "'" << std::endl;
// }

// void	ft_display(PhoneBook PhoneBook)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		std::cout << PhoneBook.Contacts[i].first_name << std::endl;
// 		i++;
// 	}
// 	// std::cout << "Displaying all the information" << std::endl;
// }

// void	PhoneBook::add(int i)
// {
// 	std::string	first_name, last_name, nickname, phone_umber, darkest_secret;

// 	std::cout << "First name: ";
// 	std::getline(std::cin, first_name);
// }

// int	main()
// {
// 	std::string	user_input;
// 	PhoneBook	PhoneBook;
// 	int			i;

// 	// std::cout << "Ahhhh, how you got to love the 80's. Nothing's been invented yet, the future is at our doorstep.\nLet's listen in\n~~~\n~~~\n~~~\n~~~\n~~~\n~~~\n~~~\n~~~\n~~~\n~~~\n~~~\n'Welcome valued customer.'\n'We appreciate your patience.'\n...\n...\n...\n'While you wait, why don't you try out our new and memory-improved phonebook service?'\n'It can hold up to 8 contacts, which should be more than enough for our world of today.'\n'Who needs to know more than 8 people anyways?'\n'Right on!'\n'Here are some instructions on how to operate this marvel of technology:'\n'Type 'ADD' to save a new contact'\n'Type 'SEARCH' to display a specific contact'\n'Type 'EXIT' to leave the program and return to your phone call.'\n";
// 	std::cout << "'Try it out now! Again: ADD, SEARCH and EXIT.'\n";
// 	i = 0;
// 	while (user_input != "EXIT")
// 	{
// 		std::getline(std::cin, user_input);
// 		if (user_input == "ADD")
// 		{
// 			PhoneBook.add(i % 8);
// 			i++;
// 		}
// 		else if (user_input == "SEARCH")
// 		{
// 			i++;
// 		}
// 	}
// }




