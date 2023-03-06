/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:55:59 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/26 19:54:15 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << B_RED << "A wild Harl appears.\n" << DEFAULT;
}

Harl::~Harl()
{
	std::cout << B_RED << "The Harl retreats!\n" << DEFAULT;
}

void	Harl::debug(void)
{
	std::cout << B_PINK << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << DEFAULT;
}

void	Harl::info(void)
{
	std::cout << B_GREEN <<  "[ INFO ] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << DEFAULT;
}

void	Harl::warning(void)
{
	std::cout << B_RED << "[ WARNING ] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here last month.\n" << DEFAULT;
}

void	Harl::error(void)
{
	std::cout << B_YELLOW << "[ ERROR ] This is unacceptable! I want to speak to the manager now.\n" << DEFAULT;
}


void	Harl::complain(std::string level)
{
	int	lvl = 0;

	if (level == "DEBUG")
		lvl = 1;
	else if (level == "INFO")
		lvl = 4;
	else if (level == "WARNING")
		lvl = 3;
	else if (level == "ERROR")
		lvl = 2;
	switch (lvl)
	{
		case 1:
			function = &Harl::debug;
			(this->*function)();
		case 2:
			function = &Harl::error;
			(this->*function)();
		case 3:
			function = &Harl::warning;
			(this->*function)();
		case 4:
			function = &Harl::info;
			(this->*function)();
			break;
		default:
			std::cout << "Unknown Error level input, Harl can't compute. . . _/\\_ . . _/\\_ . . . . . _/\\_ . . . . _/\\_____________\n";
			break;
	}
}
