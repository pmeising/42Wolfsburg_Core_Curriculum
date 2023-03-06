/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:08:35 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/16 18:33:54 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor call.\n";
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor call.\n";
}

Serializer::Serializer(const Serializer& obj)
{
	std::cout << "Serializer copy constructor call.\n";
	this->_name = obj._name;
}

// ############################## Operator overloads #########################

Serializer&	Serializer::operator=(const Serializer& rhs)
{
	std::cout << "Serializer assignment operator overload call.\n";
	this->_name = rhs._name;
	return (*this);
}

// ############################ Methods #############################

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	ui;

	ui = reinterpret_cast<uintptr_t>(ptr);
	return (ui);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data	*data;

	data = reinterpret_cast<Data*>(raw);
	return (data);
}
