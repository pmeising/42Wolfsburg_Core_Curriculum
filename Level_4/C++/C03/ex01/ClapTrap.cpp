/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:12:11 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 15:06:23 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ################################ Constructors / Destructors #########################################

ClapTrap::ClapTrap()
{
	std::cout << B_GREEN << "ClapTrap: Default constructor called.\n";
	this->setName("unknown");
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << B_GREEN << "ClapTrap: Param constructor called ClapTrap.\n";
	this->setName(name);
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
}

ClapTrap::ClapTrap(const ClapTrap& object)
{
	std::cout << B_GREEN << "ClapTrap: Copy constructor called. \n";
	this->setAttackDamage(object._attackDamage);
	this->setEnergyPoints(object._energyPoints);
	this->setHitPoints(object._hitPoints);
	this->setName(object._name);
}

ClapTrap::~ClapTrap()
{
	std::cout << B_RED << "ClapTrap: Default destructor called.\n";
}

// #################### Operator overloads #################################

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Assignment operator overload called. TrapClap\n";
	this->setAttackDamage(rhs._attackDamage);
	this->setEnergyPoints(rhs._energyPoints);
	this->setHitPoints(rhs._hitPoints);
	this->setName(rhs._name);
	return (*this);
}

// ####################### Member functions ####################################

// public ones:
void	ClapTrap::attack(const std::string& target)
{
	if (this->getHitPoints() < 1)
		std::cout << "ClapTrap " << this->getName() << " is no longer with any hit points.\n";
	else if ((this->getEnergyPoints()) < 1)
		std::cout << "ClapTrap " << this->getName() << " tries to attack " << target << ", to cause " << this->getAttackDamage() << " points of damage, but is out of energy and slides to the floor, leaving " << target << " unharmed.\n";
	else
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!\n";
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << " suffers " << amount << " points of damage to hit points! ";
	this->setHitPoints(this->getHitPoints() - amount);
	if (this->getHitPoints() < 1)
		std::cout << "This renders it unable to continue the fight. (i.e. 0 Hitpoints left)\n";
	else
		std::cout << "And is still standing strong at " << this->getHitPoints() << " hit points!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() < 1)
		std::cout << "ClapTrap " << this->getName() << " is no longer with any hit points.\n";
	else if ((this->getEnergyPoints()) < 1)
		std::cout << "ClapTrap " << this->getName() << " is out of energy points!\n";
	else
	{
		std::cout << "ClapTrap " << this->getName() << " repaires itself gaining " << amount << " hit points. Total hit points now stand at: ";
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << this->getHitPoints() << "!\n";
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

// private ones:

void	ClapTrap::setName(std::string name)
{
	_name = name;
}


void	ClapTrap::setHitPoints(unsigned int points)
{
	_hitPoints = points;
}

void	ClapTrap::setEnergyPoints(unsigned int points)
{
	_energyPoints = points;
}

void	ClapTrap::setAttackDamage(unsigned int points)
{
	_attackDamage = points;
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}
