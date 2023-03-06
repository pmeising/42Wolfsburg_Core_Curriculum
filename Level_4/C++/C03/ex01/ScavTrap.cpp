/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:13:08 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/01 20:16:24 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << B_GREEN << "ScavTrap: Default constructor called.\n";
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << B_GREEN << "ScavTrap: Param constructor called.\n";
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}


// Super interesting and important!! 
// Error message: "base class ‘class ClapTrap’ should be explicitly initialized in the copy constructor"
// The ClapTrap copy constructor needs to be called explicitly from the ScavTrap copy constructor for the program to know what to initialize.
ScavTrap::ScavTrap(const ScavTrap& object) : ClapTrap(object)
{
	std::cout << B_GREEN << "ScavTrap: Copy constructor called TrapClap.\n";
	this->setAttackDamage(object.getAttackDamage());
	this->setEnergyPoints(object.getEnergyPoints());
	this->setHitPoints(object.getHitPoints());
	this->setName(object.getName());
}

ScavTrap::~ScavTrap()
{
	std::cout << B_RED << "ScavTrap: Default destructor called.\n";
}

// #################### Operator overloads #################################

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << B_GREEN << "ScavTrap: Assignment operator overload called.\n";
	this->setAttackDamage(rhs.getAttackDamage());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setHitPoints(rhs.getHitPoints());
	this->setName(rhs.getName());
	return (*this);
}

// ################## Member functions ###############################################

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() < 1)
		std::cout << B_BLUE << "ScavTrap " << this->getName() << " has 0 hitpoints...\n";
	else if ((this->getEnergyPoints()) < 1)
		std::cout << B_BLUE << "ScavTrap " << this->getName() << " is too tired to attack " << target << "\n";
	else
	{
		std::cout << B_BLUE << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!\n";
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void	ScavTrap::guardGate()
{
	std::cout << B_BLUE << "ScavTrap " << this->getName() << " has initiated Gate-Keeper-Mode. (i.e. Hit points have increased 50%, Attack damage reduced by 50%.)\n";
	this->setHitPoints((unsigned int)(this->getHitPoints() * 1.5));
	this->setAttackDamage((unsigned int)(this->getAttackDamage() * 0.5));
}
