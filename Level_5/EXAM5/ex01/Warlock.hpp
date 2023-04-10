/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:40:23 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/04 16:04:28 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK
# define WARLOCK

# include <iostream>
# include <string>
# include <list>
# include <map>
# include "ASpell.hpp"

class ASpell;

class Warlock
{
	private:
		std::map<std::string, ASpell *>	_Spells;
		std::string						_name;
		std::string						_title;
		Warlock(); // default constr.
		Warlock(std::string name); // param constr.
		Warlock(const Warlock& obj); // copy constr.
		Warlock&		operator=(const Warlock& rhs); // assignment operator overload
	
	public:
		Warlock(std::string name, std::string title); // param constr.
		~Warlock(); // destr.

		const std::string&		getName(void) const;
		const std::string&		getTitle(void) const;
		void	setTitle(const std::string& Title);
		void	introduce() const;
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string	spell);
		void	launchSpell(std::string spell, ATarget& target);
};

#endif