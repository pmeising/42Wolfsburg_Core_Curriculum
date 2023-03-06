/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:21:51 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 18:28:00 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.h"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*Horde;
	Horde = new Zombie[N];
	int		i = 0;

	while (i < N)
	{
		Horde[i].setname(name);
		i++;
	}
	return (Horde);
}