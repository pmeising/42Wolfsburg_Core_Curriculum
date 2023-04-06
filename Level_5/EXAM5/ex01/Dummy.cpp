/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:24:03 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/06 12:19:41 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy()
{
}

Dummy::Dummy(const Dummy& obj)
{
	this->_type = obj.getType();
}

Dummy&	Dummy::operator=(const Dummy& rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

ATarget* Dummy::clone()
{
	Dummy	*obj = new Dummy;
	obj = this;
	return (obj);
}
