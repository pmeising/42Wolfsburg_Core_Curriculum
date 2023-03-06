/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:44:17 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 20:19:49 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << B_GREEN << "\nIntern: Default constructor called.\n\n" << DEFAULT;
}

Intern::Intern(const Intern& obj)
{
	obj.hm();
	std::cout << B_GREEN << "Intern: Copy constructor called on intern\n" << DEFAULT;
}

Intern::~Intern(void)
{
	std::cout << B_RED << "Intern: Default destructor called.\n" << DEFAULT;
}

// ##################### Operator overloads ###########################################

Intern& Intern::operator=(const Intern& rhs)
{
	rhs.hm();
	std::cout << B_GREEN << "Intern: Assignment operator.\n" << DEFAULT;
	return (*this);
}

// ########################## Member functions #####################

void	Intern::hm(void) const
{
	std::cout << " ";
}


// Mallocs new AForm form and returns pointer to it. Don't forget to delete it when done using!!
AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string		array[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm			*form;
	int				i;

	for (i = 0; i < 3; i++)
		if (formName == array[i])
			break;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			form = new PresidentialPardonForm(formTarget);
			break;
		default:
			std::cout << B_RED << "The Intern was unable to create the form '" << formName << "'. Form non-existent.\n" << DEFAULT;
			break;
	}
	std::cout << B_GREEN << "Intern creates " << formName << "\n" << DEFAULT;
	return (form);
}
