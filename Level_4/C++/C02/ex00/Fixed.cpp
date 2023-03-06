/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:10:47 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/27 13:04:01 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(int value)
{
	this->setRawBits(value);
	std::cout << "Constructor overload called.\n";
}

Fixed::Fixed(const Fixed& FPN_object)
{
	std::cout << "Copy constructor called. Shallow copy created.\n";
	this->setRawBits(FPN_object.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Assignment operator overload called.\n";
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called.\n";
}

int	Fixed::getRawBits(void) const // Constant functions can not change data members. They only operate with them, not on them.
{
	std::cout << "getRawBits member function called.\n";
	return (_value);
}

void	Fixed::setRawBits(int const raw) // Here the const means, that the input variable can not be adjusted.
{
	_value = raw;
}
