/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:24:03 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 21:28:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy()
{
}

ATarget* Dummy::clone()
{
	return (new Dummy());
}