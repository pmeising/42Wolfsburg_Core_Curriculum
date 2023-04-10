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
	// this->_name = "...";
	// this->_title = "noone";
	// std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::Warlock(std::string name, std::string Title) : _name(name), _title(Title)
{
	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!\n";
	std::map<std::string, ASpell*>::iterator	it = this->_Spells.begin();
	std::map<std::string, ASpell*>::iterator	it_2 = this->_Spells.end();
	while (it != it_2)
	{
		delete it->second;
		it++;
	}
}

// ##### Copy Constructor ######
Warlock::Warlock(const Warlock& obj)
{
	this->_name = obj.getName();
	this->_title = obj.getTitle();
	if (obj._Spells.size() != 0)
		this->_Spells = obj._Spells;
}

// #### Assignment operator overload #####
Warlock&	Warlock::operator=(const Warlock& rhs)
{
	std::cout << this->_name << ": It's me Assignment operator overload.\n";
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	if (rhs._Spells.size() != 0)
		this->_Spells = rhs._Spells;
	return (*this);
}

// ############# Functions ###############
const std::string&	Warlock::getName(void) const
{
	return (this->_name);
}

const	std::string&	Warlock::getTitle(void) const
{
	return (this->_title);
}

void	Warlock::setTitle(const std::string& Title)
{
	this->_title = Title;
}

void	Warlock::introduce(void) const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!\n";
}

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell)
	{
		std::map<std::string, ASpell*>::iterator	it = this->_Spells.find(spell->getName());
		if (it == this->_Spells.end())
			this->_Spells[spell->getName()] = spell->clone();
	}
}

void	Warlock::forgetSpell(std::string spell)
{
	std::map<std::string, ASpell*>::iterator	it = this->_Spells.find(spell);
	if (it != this->_Spells.end())
	{
		delete it->second;
		this->_Spells.erase(spell);
	}
}

void	Warlock::launchSpell(std::string spell, ATarget& target)
{
	std::map<std::string, ASpell*>::iterator	it = this->_Spells.find(spell);
	if (it != this->_Spells.end())
		it->second->launch(target);
}