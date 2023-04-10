/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:49:46 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/05 20:11:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{
}

ASpell::~ASpell()
{
}

ASpell::ASpell(const ASpell& obj)
{
	this->_name = obj.getName();
	this->_effects = obj.getEffects();
}

ASpell& ASpell::operator=(const ASpell& rhs)
{
	this->_name = rhs.getName();
	this->_effects = rhs.getEffects();
	return (*this);
}

std::string	ASpell::getName() const
{
	return (this->_name);	
}

std::string ASpell::getEffects() const
{
	return (this->_effects);
}

void	ASpell::launch(const ATarget& target)
{
	target.getHitBySpell(*this);
}