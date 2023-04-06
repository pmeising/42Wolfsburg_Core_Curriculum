/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:14:29 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/06 12:19:19 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::~Fwoosh()
{
}

Fwoosh::Fwoosh(const Fwoosh& obj)
{
	this->_name = obj.getName();
	this->_effects = obj.getEffects();
}

Fwoosh&	Fwoosh::operator=(const Fwoosh& rhs)
{
	this->_name = rhs.getName();
	this->_effects = rhs.getEffects();
	return (*this);
}

ASpell* Fwoosh::clone()
{
	Fwoosh	*obj = new Fwoosh;
	obj = this;
	return (obj);
}