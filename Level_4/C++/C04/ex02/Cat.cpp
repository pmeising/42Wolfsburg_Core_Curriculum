/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:38:29 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 21:14:09 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << B_GREEN << "Cat: Default constructor called.\n" << DEFAULT;
	this->setType((std::string)("Cat"));
	this->_Brain = new Brain;
	// Can't name the variable equal to the class name, that won't work.
}

Cat::Cat(const Cat& obj) : aAnimal()
{
	std::cout << B_GREEN << "Cat: Copy constructor called. \n" << DEFAULT;
	this->setType(obj.getType());
	// delete this->_Brain;
	this->_Brain = new Brain;
	*_Brain = *(obj._Brain);
	// ^^^^^ This should call the copy constructor of Brain.
}

Cat::~Cat()
{
	std::cout << B_RED << "Cat: Default destructor called.\n" << DEFAULT;
	delete _Brain;
}

// #################### Operator overloads #################################

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat: Assignment operator overload called.p\n" << DEFAULT;
	this->setType(rhs.getType());
	this->_Brain = rhs._Brain;
	return (*this);
}

// ####################### Member functions ####################################

void Cat::makeSound(void) const
{
	std::cout << "Miao...\n";
}

void	Cat::haveThought(std::string thought) const
{
	_Brain->setIdea(thought);
}

void	Cat::voiceThought(int i) const
{
	std::cout << _Brain->getIdea(i) << "\n";
}
