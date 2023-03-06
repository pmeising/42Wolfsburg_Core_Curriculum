/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:29:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 17:46:15 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie	*Zombies[5]; // Double-pointer to Zombie type array.
	int		i = 0;

	// newZombie("Carol");
	std::cout << B_BLUE << "Mallocing space for these ones inside the .newZombie function.\n" << DEFAULT;
	Zombies[0] = newZombie("Brad"); // Store pointer to first Zombie in [0].
	Zombies[1] = newZombie("Harry");
	Zombies[2] = newZombie("Mini");
	Zombies[3] = newZombie("Craspel");
	Zombies[4] = NULL;
	while (Zombies[i])
	{
		Zombies[i]->announce();
		std::cout << B_RED << "Deleting...\n" << DEFAULT;
		delete Zombies[i];
		i++;
	}
	i = 0;
	randomChump("Bills acquaintance");
	randomChump("Bills acquaintance1");
	randomChump("Bills acquaintance2");
	randomChump("Bills acquaintance3");
}
