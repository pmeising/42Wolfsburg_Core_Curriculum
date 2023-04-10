/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:42:01 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 18:46:50 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL
# define FIREBALL
# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class Fireball : public ASpell
{
	public:
		Fireball();
		~Fireball();
		ASpell* clone();
};

#endif
