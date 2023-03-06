/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:25:19 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:45:12 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// ################################ Constructors / Destructors #########################################

WrongAnimal::WrongAnimal()
{
	std::cout << B_GREEN << "WrongAnimal: Default constructor called.\n" << DEFAULT;
	this->setType((std::string)("WrongAnimal"));
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << B_GREEN << "WrongAnimal: Copy constructor called. \n" << DEFAULT;
	this->setType(obj.getType());
}

WrongAnimal::~WrongAnimal()
{
	std::cout << B_RED << "WrongAnimal: Default destructor called.\n" << DEFAULT;
}

// #################### Operator overloads #################################

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal: Assignment operator overload called.\n" << DEFAULT;
	this->setType(rhs.getType());
	return (*this);
}

// ####################### Member functions ####################################

void	WrongAnimal::setType(const std::string& type)
{
	this->_type = type;
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "~~~~~ WrongAnimal sound ~~~~~~\n";
}
