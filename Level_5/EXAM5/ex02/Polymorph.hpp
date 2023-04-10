/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:44:06 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 18:46:29 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH
# define POLYMORPH
# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class Polymorph : public ASpell
{
	public:
		Polymorph();
		~Polymorph();
		ASpell* clone();
};

#endif
