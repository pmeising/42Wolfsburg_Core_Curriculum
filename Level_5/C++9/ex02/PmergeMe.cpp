/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:40:47 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/08 23:31:25 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//======== CONSTRUCTORS =========================================================================
PmergeMe::PmergeMe() :
	_inputVector(), _inputList()
{
	// std::cout << BLU << "Default constructor called from PmergeMe" << D << "\n";
}

PmergeMe::PmergeMe(const PmergeMe& src) :
	_inputVector(src._inputVector), _inputList(src._inputList)
{
	// std::cout << BLU << "Copy constructor called from PmergeMe" << D << "\n";
}


//======== OVERLOAD OPERATORS ===================================================================
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	// std::cout << BLU << "Copy assignment operator called from PmergeMe" << D << "\n";
	if (this != & src) // check for self assignment
	{
		this->_inputVector.clear();
		this->_inputVector.insert(this->_inputVector.begin(), src._inputVector.begin(), src._inputVector.end());
		this->_inputList.clear();
		this->_inputList.insert(this->_inputList.begin(), src._inputList.begin(), src._inputList.end());
	}
	return (*this);
}


//======== DESTRUCTOR ===========================================================================
PmergeMe::~PmergeMe()
{
	// std::cout << CY << "Destructor called from PmergeMe" << D << "\n";
}


//======== GETTER / SETTER ======================================================================
std::vector<int>&	PmergeMe::getVector()
{
	return this->_inputVector;
}

std::list<int>&		PmergeMe::getList()
{
	return this->_inputList;
}


//======== MEMBER FUNCTIONS =====================================================================
void	PmergeMe::addNumberToVector(int setNumberValue)
{
	this->_inputVector.push_back(setNumberValue);
}

void	PmergeMe::addNumberToList(int setNumberValue)
{
	this->_inputList.push_back(setNumberValue);
}

void	PmergeMe::storeCollection(int argc, char **argv)
{
	for (int i = 0, value = 1; i < argc; i++)
	{
		value = atoi(argv[i]);
		this->addNumberToVector(value);
		this->addNumberToList(value);
	}
}


void	PmergeMe::printVector()
{
	std::vector<int>::iterator it;

	std::cout << "std::vector\t: ";
	for (it = getVector().begin(); it != getVector().end(); it++)
	{
		std::cout << *it << " - ";
	}
	std::cout << "\n";
}

void	PmergeMe::printList()
{
	std::list<int>::iterator	it_begin;
	std::list<int>::iterator	it_end;

	std::cout << "std::list\t: ";
	for (std::list<int>::iterator it = it_begin; it != it_end; it++)
		std::cout << *it << " - ";
	std::cout << "\n";
}

// ################################# SORTING ##########################

void	PmergeMe::sort(std::list<int> list, std::list<int>::iterator first, std::list<int>::iterator last)
{
	unsigned int	n = 1;
	for (std::list<int>::iterator it = first; it != last; it++)
		n++;
	std::cout << "This is n: " << n << std::endl;
	// std::cout << *list.begin();
	list.push_back(3);
}
