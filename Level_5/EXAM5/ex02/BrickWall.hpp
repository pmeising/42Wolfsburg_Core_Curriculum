/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BarickWall.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:48:13 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 18:48:44 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL
# define BRICKWALL
# include <iostream>
# include <string>
# include "ATarget.hpp"

class Target;

class BrickWall : public ATarget
{
	public:
		BrickWall();
		~BrickWall();
		ATarget* clone();
};

#endif
