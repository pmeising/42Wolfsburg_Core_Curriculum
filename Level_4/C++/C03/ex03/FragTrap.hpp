/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:55:23 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/06 11:36:02 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& object);
		FragTrap&	operator=(const FragTrap& rhs); // Again, rhs stands for right-hand-side.
		~FragTrap();
		
		void	attack(const std::string& target);
		void	highFivesGuys(void);

	private:
};

#endif