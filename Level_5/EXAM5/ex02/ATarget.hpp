/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:28:14 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/05 19:54:51 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET
# define ATARGET
# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string	_type;
	public:
		ATarget();
		ATarget(std::string	type);
		ATarget(const ATarget& obj);
		ATarget&	operator=(const ATarget& rhs);
		~ATarget	();
		const std::string&	getType() const;
		virtual ATarget*	clone() = 0;
		void	getHitBySpell(const ASpell& spell) const;
};

#endif
