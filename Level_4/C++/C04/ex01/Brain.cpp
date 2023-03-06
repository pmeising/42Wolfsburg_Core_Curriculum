/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:39:33 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/09 10:34:12 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << B_GREEN << "Brain: Default constructor called.\n" << DEFAULT;
	_i = 0;
}

Brain::~Brain()
{
	std::cout << B_RED << "Brain: Default destructor called.\n" << DEFAULT;
}

Brain::Brain(const Brain& obj)
{
	std::cout << B_GREEN << "Brain: Copy constructor called. \n" << DEFAULT;
	for (int i = 0; i < 100; i++)
		this->setIdea(obj.getIdea(i));
	this->_i = obj._i;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout << B_GREEN << "Brain: Assignment operator overload called.\n" << DEFAULT;
	for (int i = 0; i < 100; i++)
		this->setIdea(rhs.getIdea(i));
	this->_i = rhs._i;
	return (*this);
}

// ####################### Member functions ####################################

void	Brain::setIdea(const std::string idea)
{
	if (_i < 100)
	{
		std::string	string;

		string = idea;
		this->ideas[_i] = string;
		_i++;
	}
	else
	{
		std::cout << "Learning curve was too steep for Brain. Has a blackout and starts overwriting thoughts.\n";
		_i = 0;
	}
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < (int)_i)
		return (this->ideas[i]);
	else
	{
		return ("I can't remember that. (i.e. index out of bounds.)");
	}
}
