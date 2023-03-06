/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:15:41 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/01 18:33:21 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed	a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n----------------- Own tests ---------------------------\n\n";
	
	Fixed	c(2);
	
	std::cout << "a: " << a << "\nb: " << b << "\nc: " << c << "\n";
	
	if (a > b)
		std::cout << "a bigger b.\n";
	else
		std::cout << "a not bigger b.\n";

	if (c < b)
		std::cout << "b bigger c.\n";
	else
		std::cout << "b not bigger c.\n";

	std::cout << "c + b = :" << c + b << "\n";
	return 0;
}