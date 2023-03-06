/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:17:20 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 18:28:14 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HORDE_H
# define _ZOMBIE_HORDE_H
# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

#endif
