/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:01:25 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 20:33:12 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	Bob("Bob", 1000);
	// Bureaucrat	Linda("Linda", 4);
	Form		B27("B27", 120, 90);
	// Form		B28("B28", 3, 1);

	std::cout << "\n############################### Summary of instances ###########################\n\n";
	std::cout << Bob;
	// std::cout << Linda;
	std::cout << B27;
	// std::cout << B28;

	std::cout << "\n################################## Bob tries to sign both ######################\n\n";
	
	Bob.signForm(B27);
	// Bob.signForm(B28);
	
	// std::cout << "\n################################### Bob is working hard to get each and every promotion ##########################\n\n";
	
	// for (int i = 0; i < 30; i++)
	// 	Bob.incrementGrade();

	// std::cout << Bob;
	
	// std::cout << "\n################ Bob finally managed to grind his way up ##############################\n\n";
	
	// Bob.signForm(B27);
	// Bob.signForm(B28);
	
	// std::cout << "\n######################################## All this hard work an he's still not on the top ######################\n\n";
	
	// Linda.signForm(B28);
	// Linda.incrementGrade();
	// Linda.signForm(B28);

	// std::cout << "\n############################### Summary of instances ###########################\n\n";
	// std::cout << Bob;
	// std::cout << Linda;
	// std::cout << B27;
	// std::cout << B28;
	
	return (0);
}
