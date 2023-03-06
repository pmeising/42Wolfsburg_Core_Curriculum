/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:40:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:44:56 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << B_GREEN << "Dog: Default constructor called.\n" << DEFAULT;
	this->setType((std::string)("Dog"));
}

Dog::Dog(const Dog& obj) : Animal()
{
	std::cout << B_GREEN << "Dog: Copy constructor called. \n" << DEFAULT;
	this->setType(obj.getType());
}

Dog::~Dog()
{
	std::cout << B_RED << "Dog: Default destructor called.\n" << DEFAULT;
}

// #################### Operator overloads #################################

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog: Assignment operator overload called.p\n" << DEFAULT;
	this->setType(rhs.getType());
	return (*this);
}

// ####################### Member functions ####################################

void Dog::makeSound(void) const
{
	std::cout << "Wuff...\n";
}

