/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:52:39 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 20:57:38 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK
# define SPELLBOOK
# include <iostream>
# include <string>
# include <map>
# include <ASpell.hpp>

class ASpell;

class SpellBook
{
	private:
		std::map<std::string, ASpell*>	_Spells;
		SpellBook(const SpellBook& obj);
		SpellBook&		operator=(const SpellBook& rhs);
	
	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const &	spell);
		ASpell*	createSpell(std::string const & spell);
};



#endif
