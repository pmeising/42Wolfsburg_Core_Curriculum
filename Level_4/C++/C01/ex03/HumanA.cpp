/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:50:53 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 18:35:54 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::~HumanA()
{
	std::cout << "Default destructor HumanA called.\n";
}

HumanA::HumanA(std::string name, Weapon& type) : _weapon (type) , _name (name)
{
	std::cout << _name << " has been created. They wield a '" << _weapon.getType() << "'\n";
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their '" << _weapon.getType() << "'\n";
}
