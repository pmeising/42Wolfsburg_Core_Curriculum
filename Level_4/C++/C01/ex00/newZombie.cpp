/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:20:36 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 17:45:34 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*Zombie_ptr = new Zombie;

	Zombie_ptr->setName(name);
	return (Zombie_ptr);
}
