/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:25:05 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/05 20:27:44 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY
# define DUMMY
# include <iostream>
# include <string>
# include "ATarget.hpp"

class Target;

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();
		ATarget* clone();
};

#endif