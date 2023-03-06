/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:40:26 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 18:36:12 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <iostream>
# include <string>

// class Weapon;

class	HumanA
{
	public:
		HumanA(std::string name, Weapon& type);
		~HumanA();
		void	attack(void);
	private:
		Weapon&		_weapon;
		std::string	_name;
};

// ./HumanA.hpp:28:15: error: ‘HumanA::_name’ will be initialized after [-Werror=reorder]
//  28 |   std::string _name;
// This error occurs because when I initialize these variables in the HumanA.cpp, I initialize them in reverse order. _name first, then _weapon.


#endif