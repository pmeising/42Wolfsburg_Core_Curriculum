/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:01:25 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 19:34:59 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::string				test = "test";
	std::string				fordPrefect = "Ford Prefect";
	std::string				slartibartfast = "Slartibartfast";
	Bureaucrat				Bob("Bob", 150);
	Bureaucrat				Linda("Linda", 4);
	ShrubberyCreationForm	SCF(test);
	RobotomyRequestForm		RRF(fordPrefect);
	PresidentialPardonForm	PPF(slartibartfast);

	std::cout << "\n############################### Summary of instances ###########################\n\n";
	std::cout << Bob;
	std::cout << Linda;
	std::cout << SCF;
	std::cout << RRF;
	std::cout << PPF << "\n";

	std::cout << "\n########################### Bob can't sign anything, Linda will help him with a promotion #####################\n";

	Bob.signForm(SCF);
	Linda.signForm(SCF);
	Bob.executeForm(SCF);
	for (int i = Bob.getGrade(); i > 137; i--)
		Bob.incrementGrade();
	Bob.executeForm(SCF);

	std::cout << "\n###################### Back to not signing... ##############################\n";
	
	Bob.signForm(RRF);
	Linda.signForm(RRF);
	Bob.signForm(PPF);
	Linda.signForm(PPF);

	std::cout << "\n###################### Linda will handle this ######################\n";

	Linda.executeForm(RRF);
	Linda.executeForm(PPF);
	
	std::cout << "\n############################### Summary of instances ###########################\n\n";
	std::cout << Bob;
	std::cout << Linda;
	std::cout << SCF;
	std::cout << RRF;
	std::cout << PPF << "\n";
	
	return (0);
}
