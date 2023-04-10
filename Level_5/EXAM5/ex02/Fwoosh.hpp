/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:12:59 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/05 20:23:17 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH
# define FWOOSH
# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		Fwoosh(const Fwoosh& obj);
		Fwoosh&	operator=(const Fwoosh& rhs);
		ASpell* clone();
};

#endif