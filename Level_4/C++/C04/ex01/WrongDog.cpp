/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:40:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:44:56 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog()
{
	std::cout << B_GREEN << "WrongDog: Default constructor called.\n" << DEFAULT;
	this->setType((std::string)("WrongDog"));
}

WrongDog::WrongDog(const WrongDog& obj) : WrongAnimal()
{
	std::cout << B_GREEN << "WrongDog: Copy constructor called. \n" << DEFAULT;
	this->setType(obj.getType());
}

WrongDog::~WrongDog()
{
	std::cout << B_RED << "WrongDog: Default destructor called.\n" << DEFAULT;
}

// #################### Operator overloads #################################

WrongDog& WrongDog::operator=(const WrongDog& rhs)
{
	std::cout << "WrongDog: Assignment operator overload called.p\n" << DEFAULT;
	this->setType(rhs.getType());
	return (*this);
}

// ####################### Member functions ####################################

void WrongDog::makeSound(void) const
{
	std::cout << "Wuff...\n";
}

