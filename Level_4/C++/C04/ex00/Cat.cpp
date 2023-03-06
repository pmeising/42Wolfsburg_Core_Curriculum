/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:38:29 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:55:39 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << B_GREEN << "Cat: Default constructor called.\n" << DEFAULT;
	this->setType((std::string)("Cat"));
}

Cat::Cat(const Cat& obj) : Animal()
{
	std::cout << B_GREEN << "Cat: Copy constructor called. \n" << DEFAULT;
	this->setType(obj.getType());
}

Cat::~Cat()
{
	std::cout << B_RED << "Cat: Default destructor called.\n" << DEFAULT;
}

// #################### Operator overloads #################################

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat: Assignment operator overload called.p\n" << DEFAULT;
	this->setType(rhs.getType());
	return (*this);
}

// ####################### Member functions ####################################

void Cat::makeSound(void) const
{
	std::cout << "Miao...\n";
}