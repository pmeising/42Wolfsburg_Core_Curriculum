/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:34:18 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/06 11:50:40 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap	Jon("Jon");
	ScavTrap	Marvin("Marvin");
	FragTrap	Barney("Barney");
	DiamondTrap	Diamond_Hands("Diamond_Hands");

	std::cout << Jon.getName() << ", Hit Points: " << Jon.getHitPoints() << ", Energy Points: " << Jon.getEnergyPoints() << ", Attack Damage: " << Jon.getAttackDamage() << "\n";
	std::cout << Marvin.getName() << ", Hit Points: " << Marvin.getHitPoints() << ", Energy Points: " << Marvin.getEnergyPoints() << ", Attack Damage: " << Marvin.getAttackDamage() << "\n";
	std::cout << Barney.getName() << ", Hit Points: " << Barney.getHitPoints() << ", Energy Points: " << Barney.getEnergyPoints() << ", Attack Damage: " << Barney.getAttackDamage() << "\n";
	std::cout << Diamond_Hands.ScavTrap::getName() << ", " << Diamond_Hands.DiamondTrap::getName() << ", Hit Points: " << Diamond_Hands.ScavTrap::getHitPoints() << ", Energy Points: " << Diamond_Hands.ScavTrap::getEnergyPoints() << ", Attack Damage: " << Diamond_Hands.ScavTrap::getAttackDamage() << "\n";

	std::cout << "\nJon picks up a sword!\n\n";
	Jon.setAttackDamage(5);
	std::cout << Jon.getName() << ", Hit Points: " << Jon.getHitPoints() << ", Energy Points: " << Jon.getEnergyPoints() << ", Attack Damage: " << Jon.getAttackDamage() << "\n";
	std::cout << "Jon picks up a shield!\n";
	Jon.setHitPoints(Jon.getHitPoints() + 20);
	std::cout << Jon.getName() << ", Hit Points: " << Jon.getHitPoints() << ", Energy Points: " << Jon.getEnergyPoints() << ", Attack Damage: " << Jon.getAttackDamage() << "\n";

	Jon.attack("Marvin");
	Marvin.takeDamage(Jon.getAttackDamage());
	
	Marvin.guardGate();
	std::cout << Marvin.getName() << ", Hit Points: " << Marvin.getHitPoints() << ", Energy Points: " << Marvin.getEnergyPoints() << ", Attack Damage: " << Marvin.getAttackDamage() << "\n";
	Marvin.attack("Jon");
	Jon.takeDamage(Marvin.getAttackDamage());

	std::cout << "\n";

	Jon.attack("Marvin");
	Marvin.takeDamage(Jon.getAttackDamage());
	Marvin.attack("Jon");
	Jon.takeDamage(Marvin.getAttackDamage());
	// Marvin.attack("the wall");

	Barney.attack("Jon");
	Jon.takeDamage(Barney.getAttackDamage());
	
	// Things that won't work:
	// Jon.guardGate();
	Marvin.guardGate();
	// Barney.guardGate();

	// Jon.highFivesGuys();
	// Marvin.highFivesGuys();
	Barney.highFivesGuys();
	
	std::cout << "\n\nDiamondHands can do anything, watch!!\n\n";

	Diamond_Hands.guardGate();
	Diamond_Hands.highFivesGuys();
	Diamond_Hands.attack("The fabric of space");
	Diamond_Hands.whoAmI();

	
	return (0);
}
