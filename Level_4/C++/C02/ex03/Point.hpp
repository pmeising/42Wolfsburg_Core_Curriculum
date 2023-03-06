/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:48:29 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/30 15:54:02 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "iostream"
# include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& pointObject);
		Point& operator=(const Point& rhs);
		~Point();
		
		void	setX(const float x);
		void	setY(const float y);
		Fixed	getX() const;
		Fixed	getY() const;
	
	private:
		Fixed	_x;
		Fixed	_y;
};

#endif
