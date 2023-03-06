/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:17:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 18:21:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default constructor called.\n";
}

Zombie::~Zombie()
{
	std::cout << "Deconstructor call of: " << _name << "\n";
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setname(std::string name)
{
	_name = name;
}

// Zombie	*zombieHorde(int N, std::string name)
// {
// 	Zombie	*Horde;
// 	Horde = new Zombie[N];
// 	int		i = 0;

// 	while (i < N)
// 	{
// 		Horde[i].setname(name);
// 		i++;
// 	}
// 	return (Horde);
// }
