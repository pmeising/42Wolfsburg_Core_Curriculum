/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:47:54 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/06 11:48:39 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& object);
		DiamondTrap&	operator=(const DiamondTrap& rhs); // Again, rhs stands for right-hand-side.
		~DiamondTrap();
		std::string&	getName();
		void	setName(std::string& name);
		void	attack(const std::string& target);
		void	whoAmI();
	
	private:
		std::string	_name;
};

// The Diamond Problem is an ambiguity that arises in multiple inheritance when two parent classes 
// inherit from the same grandparent class, and both parent classes are inherited by a single child class.
// Without using virtual inheritance, the child class would inherit the properties of the grandparent class
// twice, leading to ambiguity.

// This can crop up frequently in real-world code, so it's important to address that ambiguity whenever
// it's spotted.

// The Diamond Problem is fixed using virtual inheritance, in which the virtual keyword is used when
// parent classes inherit from a shared grandparent class. By doing so, only one copy of the grandparent
// class is made, and the object construction of the grandparent class is done by the child class.
// https://www.makeuseof.com/what-is-diamond-problem-in-cpp/

#endif