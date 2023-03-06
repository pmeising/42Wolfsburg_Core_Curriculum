/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:34:18 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/01 20:19:29 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	Jon("Jon");
	ScavTrap	Marvin("Marvin");

	std::cout << Jon.getName() << ", Hit Points: " << Jon.getHitPoints() << ", Energy Points: " << Jon.getEnergyPoints() << ", Attack Damage: " << Jon.getAttackDamage() << "\n";
	std::cout << Marvin.getName() << ", Hit Points: " << Marvin.getHitPoints() << ", Energy Points: " << Marvin.getEnergyPoints() << ", Attack Damage: " << Marvin.getAttackDamage() << "\n";

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
	return (0);
}
