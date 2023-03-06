/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:40:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 22:26:13 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << B_GREEN << "Dog: Default constructor called. Brain malloced.\n" << DEFAULT;
	this->setType((std::string)("Dog"));
	this->_Brain = new Brain;
}

Dog::Dog(const Dog& obj) : Animal()
{
	std::cout << B_GREEN << "Dog: Copy constructor called. Brain malloced\n" << DEFAULT;
	this->setType(obj.getType());
	this->_Brain = new Brain;
	*_Brain = *(obj._Brain);
}

Dog::~Dog()
{
	std::cout << B_RED << "Dog: Default destructor called.\n" << DEFAULT;
	delete _Brain;
}

// #################### Operator overloads #################################

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog: Assignment operator overload called.p\n" << DEFAULT;
	this->setType(rhs.getType());
	this->_Brain = rhs._Brain;
	return (*this);
}

// ####################### Member functions ####################################

void Dog::makeSound(void) const
{
	std::cout << "Wuff...\n";
}

void	Dog::haveThought(std::string thought)
{
	_Brain->setIdea(thought);
}

void	Dog::voiceThought(int i)
{
	std::cout << _Brain->getIdea(i) << "\n";
}
