/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:28:14 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 18:30:16 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL
# define ASPELL
# include <iostream>
# include <string>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string	_name;
		std::string	_effects;
	public:
		ASpell();
		ASpell(std::string	name, std::string effects);
		ASpell(const ASpell& obj); // copy constr.
		ASpell&		operator=(const ASpell& rhs); // assignment operator overload
		virtual ~ASpell	();
		std::string	getName() const;
		std::string	getEffects() const;
		virtual ASpell*	clone() = 0;
		void	launch(const ATarget& target);
};

#endif
