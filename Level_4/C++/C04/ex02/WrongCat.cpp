/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:38:29 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:55:39 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << B_GREEN << "WrongCat: Default constructor called.\n" << DEFAULT;
	this->setType((std::string)("WrongCat"));
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal()
{
	std::cout << B_GREEN << "WrongCat: Copy constructor called. \n" << DEFAULT;
	this->setType(obj.getType());
}

WrongCat::~WrongCat()
{
	std::cout << B_RED << "WrongCat: Default destructor called.\n" << DEFAULT;
}

// #################### Operator overloads #################################

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat: Assignment operator overload called.p\n" << DEFAULT;
	this->setType(rhs.getType());
	return (*this);
}

// ####################### Member functions ####################################

void WrongCat::makeSound(void) const
{
	std::cout << "Miao...\n";
}