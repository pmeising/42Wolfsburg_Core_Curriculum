/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:03:19 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/04 18:21:17 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

int	main(void)
{
	{
		Warlock	A("Branda", "The great");
		Warlock	B("Will", "the weird");

		std::cout << A.getName() << " " << A.getTitle() << ": says hello.\n";
		std::cout << B.getName() << " " << B.getTitle() << ": says hello.\n";
	}
	{
		Warlock const richard("Richard", "Mistress of Magma");
		richard.introduce();
		std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

		Warlock* jack = new Warlock("Jack", "the Long");
		jack->introduce();
		jack->setTitle("the Mighty");
		jack->introduce();

		delete jack;
	}
	return (0);
}
