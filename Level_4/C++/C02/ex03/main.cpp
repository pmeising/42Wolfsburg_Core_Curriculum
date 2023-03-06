/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:15:41 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/01 18:36:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	ft_in_triangle(Point& a, Point& b, Point& c, Point& p)
{
	// [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
	float	A = abs(((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) + (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) + (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2.0);
	// replace a
	float	A_1 = abs(((p.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) + (b.getX().toFloat() * (c.getY().toFloat() - p.getY().toFloat())) + (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2.0);
	// replace b
	float	A_2 = abs(((a.getX().toFloat() * (p.getY().toFloat() - c.getY().toFloat())) + (p.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) + (c.getX().toFloat() * (a.getY().toFloat() - p.getY().toFloat()))) / 2.0);
	// replace c
	float	A_3 = abs(((a.getX().toFloat() * (b.getY().toFloat() - p.getY().toFloat())) + (b.getX().toFloat() * (p.getY().toFloat() - a.getY().toFloat())) + (p.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2.0);
	// std::cout << "A_1, A_2, A_3 and A: " << A_1 << " " << A_2 << " " << A_3 << " " << A << " \n";
	if ((A_1 + A_2 + A_3) == A)
		return true;
	return false;
}

int main(int argc, char **argv)
{
	Point	a(0.0f, 0.0f);
	Point	b(1.0f, 0.0f);
	Point	c(1.0f, 1.0f);

	std::cout << "a is located at: "<< a.getX() << ", ";
	std::cout << a.getY() << "\n";
	std::cout << "b is located at: "<< b.getX() << ", ";
	std::cout << b.getY() << "\n";
	std::cout << "c is located at: "<< c.getX() << ", ";
	std::cout << c.getY() << "\n";

	if (argc == 3)
	{
		Point p(atof(argv[1]), atof(argv[2])); // atof = ascii to float. Converts string to float
		if (ft_in_triangle(a, b, c, p))
			std::cout << "Point P lies inside the triangle!\n";
		else
			std::cout << "Point P does not lie inside the triangle!\n";
	}	
	return 0;
}