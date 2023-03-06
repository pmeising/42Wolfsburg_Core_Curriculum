/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:21:30 by pmeising          #+#    #+#             */
/*   Updated: 2023/03/02 16:57:02 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0), _vec(std::vector<int>(0))
{
	std::cout << B_GREEN << "Default constructor called.\n";
}

Span::Span(unsigned int N) : _size(N), _vec(std::vector<int>(N))
{
	std::cout << B_GREEN << "Constructor call.\nAllocating space for a vector pointer capable of holding " << N << " ints.\n" << DEFAULT;
	for(unsigned int i = 0; i < this->_size; i++)
		this->_vec[i] = 0;
}

Span::Span(const Span& obj) : _size(obj._size)
{
	std::cout << "Copy constructor called.\n";
	this->_vec = std::vector<int>(obj._vec);
}

Span::~Span()
{
	std::cout << B_RED << "Destructor call.\n" << DEFAULT;
}

// ############################# Operator overloads ############################

Span&	Span::operator=(const Span& rhs)
{
	std::cout << "Copy constructor called.\n";
	for (unsigned int i = 0; i < rhs._size; i++)
		this->_vec[i] = rhs._vec[i];
	this->_size = rhs._size;
	return (*this);
}

// ############################### Member functions ################################

std::vector<int>	Span::get_vec(void)
{
	return (this->_vec);
}

void	Span::addNumber(int nbr)
{
	int count = std::count(_vec.begin(), _vec.end(), 0);
	if (count > 0)
		this->_vec[this->_size - count] = nbr;
	else
		throw std::exception();
}

unsigned long	Span::shortestSpan()
{

	if (_vec.size() - (std::count(_vec.begin(), _vec.end(), 0)) <= 1)
		throw std::exception();
	else
	{
		std::sort(_vec.begin(), _vec.end());
		std::vector<int>			results(_vec.size());
		std::vector<int>::iterator	result = results.begin();
		// std::cout << "\n####################### Creating Vector with Adjacent differences values #############\n";
		std::adjacent_difference(_vec.begin(), _vec.end(), result);
		std::vector<int>::iterator	min = std::min_element(results.begin(), results.end());
		return (*min);
	}
	return (42);
}

unsigned long	Span::longestSpan()
{

	if (_vec.size() - (std::count(_vec.begin(), _vec.end(), 0)) <= 1)
		throw std::exception();
	else
	{
		std::vector<int>::iterator	min = std::min_element(_vec.begin(), _vec.end());
		std::vector<int>::iterator	max = std::max_element(_vec.begin(), _vec.end());
		return (*max - *min);
	}
	return (42);
}
