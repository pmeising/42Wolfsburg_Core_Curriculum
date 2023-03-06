/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:25:19 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 17:52:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ################################ Constructors / Destructors #########################################

Animal::Animal()
{
	std::cout << B_GREEN << "Animal: Default constructor called.\n" << DEFAULT;
	this->setType((std::string)("Animal"));
}

Animal::Animal(const Animal& obj)
{
	std::cout << B_GREEN << "Animal: Copy constructor called. \n" << DEFAULT;
	this->setType(obj.getType());
}

Animal::~Animal()
{
	std::cout << B_RED << "Animal: Default destructor called.\n" << DEFAULT;
}

// #################### Operator overloads #################################

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal: Assignment operator overload called.\n" << DEFAULT;
	this->setType(rhs.getType());
	return (*this);
}

// ####################### Member functions ####################################

void	Animal::setType(const std::string& type)
{
	this->_type = type;
}

std::string Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "~~~~~ Animal sound ~~~~~~\n";
}
