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

// ################# CONSTRUCTORS / DESTRUCTORS + OVERLOADS ##########################

Fixed::Fixed()
{
	_value = 0;
	// std::cout << "Default constructor called. ~Fixed~ \n";
}

Fixed::Fixed(const int value)
{
	// std::cout << "Constructor overload (int) called. ~Fixed~ \n";
	this->setRawBits((value << 8));
}

Fixed::Fixed(const float value)
{
	// std::cout << "Constructor overload (float) called. ~Fixed~ \n";
	this->setRawBits((int)(roundf(value * (float)(1 << 8))));
	// What this does is that it bitshifts the binary representation of 1 (i.e. 0000 0001.) 
	// 8 bits to the left, with the decimal point remaining static. The endresult looks like
	// we moved the decimal point: .1000 0000
}

// Copy constructor
Fixed::Fixed(const Fixed& FPN_object)
{
	// std::cout << "Copy constructor called. Shallow copy created. ~Fixed~ \n";
	this->setRawBits(FPN_object.getRawBits());
}

// Destructor

Fixed::~Fixed()
{
	// std::cout << "Destructor called. ~Fixed~ \n";
}


// ####################### Operator Overloads ########################################

Fixed& Fixed::operator=(const Fixed& rhs)
{
	// std::cout << "Assignment operator overload called. ~Fixed~ \n";
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

bool	Fixed::operator>(const Fixed& a)
{
	if (this->toFloat() > a.toFloat())
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed& a)
{
	if (this->toFloat() < a.toFloat())
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed& a)
{
	if (this->toFloat() >= a.toFloat())
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed& a)
{
	if (this->toFloat() <= a.toFloat())
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed& a)
{
	if (this->toFloat() == a.toFloat())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed& a)
{
	if (this->toFloat() != a.toFloat())
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed& a)
{
	Fixed	result(this->toFloat() + a.toFloat());

	return (result);
}

Fixed	Fixed::operator-(const Fixed& a)
{
	Fixed	result(this->toFloat() - a.toFloat());

	return (result);
}

Fixed	Fixed::operator*(const Fixed& a)
{
	Fixed	result(this->toFloat() * a.toFloat());

	return (result);
}

Fixed	Fixed::operator/(const Fixed& a)
{
	Fixed	result(this->toFloat() / a.toFloat());

	return (result);
}

Fixed	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	old(*this);
	++(*this);
	return (old);
}

Fixed	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	old(*this);
	--(*this);
	return (old);
}

// ################################### Member functions ######################################

int	Fixed::getRawBits(void) const // Constant functions can not change data members. They only operate with them, not on them.
{
	// std::cout << "getRawBits member function called.\n";
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) // Here the const means, that the input variable can not be adjusted.
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)((getRawBits() / (float)(1 << 8))));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> 8);
}


Fixed	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}


Fixed	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}


Fixed	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}



// ################################ Global functions ###############################


std::ostream& operator<<(std::ostream& stream, const Fixed& obj)
{
	stream << obj.toFloat();
	// The stream object is being inserted the float point rep by calling the toFloat() mem-func. of hte Fixed class object "obj".
	return (stream);
}
