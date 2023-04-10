/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:39:40 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 20:50:51 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	if (this->_Spells.size() == 0)
		return;
	std::map<std::string, ASpell *>::iterator	it = this->_Spells.begin();
	while (it != this->_Spells.end())
	{
		delete it->second;
		it++;
	}
}

// ##### Copy Constructor ######
SpellBook::SpellBook(const SpellBook& obj)
{
	if (obj._Spells.size() != 0)
		this->_Spells = obj._Spells;
}

// #### Assignment operator overload #####
SpellBook&	SpellBook::operator=(const SpellBook& rhs)
{
	if (rhs._Spells.size() != 0)
		this->_Spells = rhs._Spells;
	return (*this);
}

// ############# Functions ###############
void	SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		std::map<std::string, ASpell*>::iterator	it = this->_Spells.find(spell->getName());
		if (it == this->_Spells.end())
			this->_Spells[spell->getName()] = spell->clone();
	}
}

void	SpellBook::forgetSpell(std::string const & spell)
{
	std::map<std::string, ASpell*>::iterator	it = this->_Spells.find(spell);
	if (it != this->_Spells.end())
	{
		delete it->second;
		this->_Spells.erase(spell);
	}
}

ASpell*	SpellBook::createSpell(std::string const & spell)
{
	std::map<std::string, ASpell*>::iterator	it = this->_Spells.find(spell);
	if (it != this->_Spells.end())
	{
		return (it->second->clone());
	}
	return (NULL);
}
