/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:30:17 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 16:14:59 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
{
	// std::cout << "Default Point constructor called. ~Point~ \n";
	this->setX(0.0f);
	this->setY(0.0f);
}

Point::Point(const float x, const float y)
{
	// std::cout << "Float Point constructor called. ~Point~ \n";
	this->setX(x);
	this->setY(y);
}

Point::Point(const Point& pointObject)
{
	// std::cout << "Point copy constructor called. Shallow copy created. ~Point~ \n";
	this->setX(pointObject.getX().getRawBits());
	this->setY(pointObject.getY().getRawBits());
}

Point&	Point::operator=(const Point& rhs)
{
	// std::cout << "Point assignment operator overload called. ~Point~ \n";
	this->setX(rhs.getX().getRawBits());
	this->setY(rhs.getY().getRawBits());
	return (*this);
}

Point::~Point()
{
	// std::cout << "Default Point destructor called. ~Point~ \n";
}

// #################################### Member functions: ################################

void	Point::setX(const float x)
{
	_x = Fixed(x);
}

void	Point::setY(const float y)
{
	_y = Fixed(y);
}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}

