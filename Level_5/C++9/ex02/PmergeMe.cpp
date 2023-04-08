/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:40:47 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/08 23:02:53 by pmeising         ###   ########.fr       */
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
std::vector<int>&	PmergeMe::getInputVector()
{
	return this->_inputVector;
}

std::list<int>&		PmergeMe::getInputList()
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
	for (int i, value = 1; i < argc; i++)
	{
		value = atoi(argv[i]);
		this->addNumberToVector(value);
		this->addNumberToList(value);
	}
}


void	PmergeMe::printInputVector()
{
	std::vector<int>::iterator it;

	std::cout << "std::vector\t: ";
	for (it = getInputVector().begin(); it != getInputVector().end(); it++)
	{
		std::cout << *it << " - ";
	}
	std::cout << "\n";
}

void	PmergeMe::printInputList()
{
	std::list<int>::iterator it;

	std::cout << "std::list\t: ";
	for (it = getInputList().begin(); it != getInputList().end(); it++)
	{
		std::cout << *it << " - ";
	}
	std::cout << "\n";
}

