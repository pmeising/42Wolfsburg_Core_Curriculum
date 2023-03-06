/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:13:08 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/01 22:11:41 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << B_GREEN << "FragTrap: Default constructor called.\n";
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << B_GREEN << "FragTrap: Param constructor called.\n";
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}


// Super interesting and important!! 
// Error message: "base class ‘class ClapTrap’ should be explicitly initialized in the copy constructor"
// The ClapTrap copy constructor needs to be called explicitly from the FragTrap copy constructor for the program to know what to initialize.
FragTrap::FragTrap(const FragTrap& object) : ClapTrap(object)
{
	std::cout << B_GREEN << "FragTrap: Copy constructor called.\n";
	this->setAttackDamage(object.getAttackDamage());
	this->setEnergyPoints(object.getEnergyPoints());
	this->setHitPoints(object.getHitPoints());
	this->setName(object.getName());
}

FragTrap::~FragTrap()
{
	std::cout << B_RED << "FragTrap: Default destructor called.\n";
}

// #################### Operator overloads #################################

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << B_GREEN << "FragTrap: Assignment operator overload called.\n";
	this->setAttackDamage(rhs.getAttackDamage());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setHitPoints(rhs.getHitPoints());
	this->setName(rhs.getName());
	return (*this);
}

// ################## Member functions ###############################################

void	FragTrap::attack(const std::string& target)
{
	if (this->getHitPoints() < 1)
		std::cout << B_BLUE << "FragTrap " << this->getName() << " has 0 hitpoints...\n";
	else if ((this->getEnergyPoints()) < 1)
		std::cout << B_BLUE << "FragTrap " << this->getName() << " is too tired to attack " << target << "\n";
	else
	{
		std::cout << B_BLUE << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!\n";
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Up high, down low, high fives all day yo.\n";
}
