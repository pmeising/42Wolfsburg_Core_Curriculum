/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:26 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 18:39:09 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	_type = "'greasy finger'";
	std::cout << "No weapon supplied ... I'll fight with my " << "\n";
}

Weapon::~Weapon()
{
	std::cout << "Default destructor called Weapon.\n";
}

Weapon::Weapon(std::string weapon_type)
{
	_type = weapon_type;
	std::cout << "Weapon '" << _type << "' created successfully\n";
}

const std::string&	Weapon::getType()
{
	const	std::string &type = _type;
	return (type);
}

void	Weapon::setType(std::string type)
{
	if (type.length() != 0)
		_type = type;
	else
		_type = "'rotten banana leaf'";
}
