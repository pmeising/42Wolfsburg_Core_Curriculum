/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:34:18 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 15:06:23 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Bart("Bart");
	ClapTrap	Lisa("Lisa");
	ClapTrap	Maggie("Maggie");
	ClapTrap	Homer("Homer");
	int			i = 0;
	
	std::cout << B_GREEN << "\n\nMinor disagreement between siblings.\n\n" << DEFAULT;
	Bart.attack("Lisa");
	Lisa.takeDamage(Bart.getAttackDamage());
	
	Maggie.attack("Bart");
	Bart.takeDamage(Maggie.getAttackDamage());

	Lisa.attack("Bart");
	Bart.takeDamage(Lisa.getAttackDamage());

	std::cout << B_BLUE << "    Homer steps in and singles out Bart for a beating...\n\n" << DEFAULT;
	Homer.setAttackDamage(1);
	Homer.setHitPoints(50);
	while (i < 10)
	{
		Homer.attack("Bart");
		Bart.takeDamage(Homer.getAttackDamage());
		std::cout << B_GREEN;
		Bart.beRepaired(1);
		std::cout << B_BLUE;
		i++;
	}
	std::cout << DEFAULT << "Homer feels tired all of a sudden.\n\n";

	Homer.attack("Bart");
	Bart.takeDamage(0);
	
	std::cout << DEFAULT << "Lisa and Maggie pity their brother and play 'Homer Piñata' \n\n'";
	
	Bart.setEnergyPoints(1);
	Bart.beRepaired(2);
	Lisa.beRepaired(3);
	std::cout << B_GREEN << "Maggie eats a protein bar from her baby food drawer.\n\n" << DEFAULT;
	Maggie.setAttackDamage(10);
	Maggie.attack("Homer");
	Homer.takeDamage(Maggie.getAttackDamage());

	std::cout << "After a long day of parenting and not having 0 children and 3 money, Homer sits down to eat.\n\n" << B_GREEN;

	Homer.setEnergyPoints(1);
	Homer.beRepaired(100);
	
	std::cout << DEFAULT;
	
	std::cout << Homer.getName() << ", Hit Points: " << Homer.getHitPoints() << ", Energy Points: " << Homer.getEnergyPoints() << ", Attack Damage: " << Homer.getAttackDamage() << "\n";
	std::cout << Lisa.getName() << ", Hit Points: " << Lisa.getHitPoints() << ", Energy Points: " << Lisa.getEnergyPoints() << ", Attack Damage: " << Lisa.getAttackDamage() << "\n";
	std::cout << Bart.getName() << ", Hit Points: " << Bart.getHitPoints() << ", Energy Points: " << Bart.getEnergyPoints() << ", Attack Damage: " << Bart.getAttackDamage() << "\n";
	std::cout << Maggie.getName() << ", Hit Points: " << Maggie.getHitPoints() << ", Energy Points: " << Maggie.getEnergyPoints() << ", Attack Damage: " << Maggie.getAttackDamage() << "\n";

	return (0);
}
