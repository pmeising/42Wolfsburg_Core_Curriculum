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
	this->_name = "...";
	this->_title = "noone";
	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::Warlock(std::string name, std::string Title) : _name(name), _title(Title)
{
	std::cout << this->_name << ": This looks like another boring day.\n";
	this->_i = 0;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!\n";
}

// ##### Copy Constructor ######
Warlock::Warlock(const Warlock& obj)
{
	std::cout << this->_name << ": It's me copy-constructor.\n";
	this->_name = obj.getName();
	this->_title = obj.getTitle();
	this->_i = obj._i;
	int i;
	while (i < _i)
	{
		this->_spells[i] = obj._spells[i];
		i++;
	}
}

// #### Assignment operator overload #####
Warlock&	Warlock::operator=(const Warlock& rhs)
{
	std::cout << this->_name << ": It's me Assignment operator overload.\n";
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	int i;
	while (i < _i)
	{
		this->_spells[i] = rhs._spells[i];
		i++;
	}
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
	this->_spells[this->_i] = spell;
	this->_i++;
}

void	Warlock::forgetSpell(std::string spell)
{
	int i;
	while (i < this->_i && this->_spells[i]->getName() != spell)
		i++;
	if (this->_spells[i]->getName() == spell)
		this->_spells[i] = NULL;
}

void	Warlock::launchSpell(std::string spell, ATarget& target)
{
	int i;
	while (i < this->_i && this->_spells[i]->getName() != spell)
		i++;
	if (this->_spells[i]->getName() == spell)
		target.getHitBySpell(*this->_spells[i]);

}