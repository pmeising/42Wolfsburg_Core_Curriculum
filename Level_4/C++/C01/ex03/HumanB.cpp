/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:14:32 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 18:37:18 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanB::HumanB(std::string name) : _name (name)
{
	std::cout << _name << " has been created.\n";
}

HumanB::~HumanB()
{
	std::cout << "Default destructor called HumanB.\n";
}

void	HumanB::setWeapon(Weapon& weapon_type)
{
	_weapon = &weapon_type;
	std::cout << _name << " now wields a '" << (*_weapon).getType() << "'\n";
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their '" << (*_weapon).getType() << "'\n";
}