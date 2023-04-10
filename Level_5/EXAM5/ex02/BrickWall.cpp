/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:49:01 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 18:52:07 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::~BrickWall()
{
}

ATarget* BrickWall::clone()
{
	BrickWall	*obj = new BrickWall;
	obj = this;
	return (obj);
}
