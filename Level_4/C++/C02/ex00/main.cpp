/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:15:41 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/01 18:22:59 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed fpn1(4);
	Fixed fpn2(2);

	std::cout << fpn1.getRawBits() << "\n";
	Fixed	fpn3 = fpn2;
	std::cout << fpn2.getRawBits() << "\n";
	std::cout << fpn3.getRawBits() << "\n";
	return (0);
}

// int main( void )
// {
// 	Fixed a; // Calls default constructor
// 	Fixed b(a); // Calls copy constructor
// 	Fixed c; // Calls default constructor

// 	c = b;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
// 	return 0;
// }