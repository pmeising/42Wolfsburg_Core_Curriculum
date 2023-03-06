/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:25:19 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 17:52:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aAnimal.hpp"

// ################################ Constructors / Destructors #########################################

aAnimal::aAnimal()
{
	std::cout << B_GREEN << "aAnimal: Default constructor called.\n" << DEFAULT;
	this->setType((std::string)("aAnimal"));
}

aAnimal::aAnimal(const aAnimal& obj)
{
	std::cout << B_GREEN << "aAnimal: Copy constructor called. \n" << DEFAULT;
	this->setType(obj.getType());
}

aAnimal::~aAnimal()
{
	std::cout << B_RED << "aAnimal: Default destructor called.\n" << DEFAULT;
}

// #################### Operator overloads #################################

aAnimal& aAnimal::operator=(const aAnimal& rhs)
{
	std::cout << "aAnimal: Assignment operator overload called.\n" << DEFAULT;
	this->setType(rhs.getType());
	return (*this);
}

// ####################### Member functions ####################################

void	aAnimal::setType(const std::string& type)
{
	this->_type = type;
}

std::string aAnimal::getType(void) const
{
	return (_type);
}

void	aAnimal::makeSound(void) const
{
	std::cout << "~~~~~ aAnimal sound ~~~~~~\n";
}
