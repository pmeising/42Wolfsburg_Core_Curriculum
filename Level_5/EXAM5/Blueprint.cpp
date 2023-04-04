/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blueprint.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:43:05 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/04 16:07:49 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Blueprint.hpp"

Blueprint::Blueprint()
{
	this->_name = "...";
	this->_id = 0;
	std::cout << this->_name << ": It's me constructor.\n";
}

Blueprint::Blueprint(std::string name) : _name(name), _id(0)
{
	std::cout << this->_name << ": It's me param-constructor.\n";
}

Blueprint::Blueprint(std::string name, unsigned int i) : _name(name), _id(i)
{
	std::cout << this->_name << ": It's me param-constructor.\n";
}

Blueprint::~Blueprint()
{
	std::cout << this->_name << ": It's me destructor.\n";
}

// ##### Copy Constructor ######
Blueprint::Blueprint(const Blueprint& obj)
{
	std::cout << this->_name << ": It's me copy-constructor.\n";
	this->_name = obj.getName();
	this->_id = obj.getId();
}

// #### Assignment operator overload #####
Blueprint&	Blueprint::operator=(const Blueprint& rhs)
{
	std::cout << this->_name << ": It's me Assignment operator overload.\n";
	this->_name = rhs.getName();
	this->_id = rhs.getId();
	return (*this);
}

// ############# Functions ###############
std::string	Blueprint::getName(void) const
{
	return (this->_name);
}

unsigned int	Blueprint::getId(void) const
{
	return (this->_id);
}