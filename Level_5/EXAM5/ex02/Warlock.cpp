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
}

Warlock::Warlock(std::string name, std::string Title) : _name(name), _title(Title)
{
	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!\n";
}

// ##### Copy Constructor ######
Warlock::Warlock(const Warlock& obj)
{
	this->_name = obj.getName();
	this->_title = obj.getTitle();
}

// #### Assignment operator overload #####
Warlock&	Warlock::operator=(const Warlock& rhs)
{
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
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
	this->_SpellBook.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spell)
{
	this->_SpellBook.forgetSpell(spell);
}

void	Warlock::launchSpell(std::string spell, ATarget& target)
{
	ASpell	*retrievedSpell = this->_SpellBook.createSpell(spell);
	if (retrievedSpell)
		retrievedSpell->launch(target);
}