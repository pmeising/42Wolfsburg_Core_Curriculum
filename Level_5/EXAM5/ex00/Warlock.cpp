/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:43:05 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/04 16:07:49 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock()
{
	this->name = "...";
	this->title = "noone";
	std::cout << this->name << ": This looks like another boring day.\n";
}

// Warlock::Warlock(std::string name) : name(name), title(0)
// {
// 	std::cout << this->name << ": It's me param-constructor.\n";
// }

Warlock::Warlock(std::string name, std::string Title) : name(name), title(Title)
{
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!\n";
}

// ##### Copy Constructor ######
Warlock::Warlock(const Warlock& obj)
{
	std::cout << this->name << ": It's me copy-constructor.\n";
	this->name = obj.getName();
	this->title = obj.getTitle();
}

// #### Assignment operator overload #####
Warlock&	Warlock::operator=(const Warlock& rhs)
{
	std::cout << this->name << ": It's me Assignment operator overload.\n";
	this->name = rhs.getName();
	this->title = rhs.getTitle();
	return (*this);
}

// ############# Functions ###############
const std::string&	Warlock::getName(void) const
{
	return (this->name);
}

const	std::string&	Warlock::getTitle(void) const
{
	return (this->title);
}

void	Warlock::setTitle(const std::string& Title)
{
	this->title = Title;
}

void	Warlock::introduce(void) const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!\n";
}
