/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:49:46 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/05 20:06:22 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::ATarget(std::string type) : _type(type)
{
}

ATarget::~ATarget()
{
}

ATarget::ATarget(const ATarget& obj)
{
	this->_type = obj.getType();
}

ATarget& ATarget::operator=(const ATarget& rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

const std::string&	ATarget::getType() const
{
	return (this->_type);
}

void	ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
