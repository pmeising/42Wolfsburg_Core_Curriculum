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
# include "SpellBook.hpp"

class ASpell;
class SpellBook;

class Warlock
{
	private:
		SpellBook		_SpellBook;
		std::string		_name;
		std::string		_title;
		Warlock();
		Warlock(std::string name);
		Warlock(const Warlock& obj);
		Warlock&		operator=(const Warlock& rhs);
	
	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		const std::string&		getName(void) const;
		const std::string&		getTitle(void) const;
		void	setTitle(const std::string& Title);
		void	introduce() const;
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string	spell);
		void	launchSpell(std::string spell, ATarget& target);
};

#endif