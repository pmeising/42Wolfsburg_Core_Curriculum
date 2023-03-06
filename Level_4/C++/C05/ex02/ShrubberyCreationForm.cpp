/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:07:07 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 18:53:42 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << B_GREEN << "ShrubberyCreationForm default constructor.\n" << DEFAULT;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << B_GREEN << "ShrubberyCreationForm param constructor.\n" << DEFAULT;
	this->_target = (target +  "_shrubbery");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExec())
{
	std::cout << B_GREEN << "ShrubberyCreationForm copy constructor.\n" << DEFAULT;
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << B_RED << "ShrubberyCreationForm destructor.\n" << DEFAULT;
}

// ######################## Operator overloads #######################

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << B_GREEN << "ShrubberyCreationForm assignement operator overload.\n" << DEFAULT;
	this->_target = rhs.getTarget();
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

bool	ShrubberyCreationForm::beSigned(const Bureaucrat& obj)
{
	try
	{
		if (obj.getGrade() > this->getGradeSign())
			throw GradeTooLowException(); // is the GTLE from AForm class
		else if (obj.getGrade() < 1)
			throw GradeTooHighException(); // is the GTLE from AForm class
		else
		{
			this->sign();
			return (true);
		}
	}
	catch(const std::exception& e) // doesn't pick up on it.
	{
		std::cout << B_RED << "Exception thrown: " << e.what() << "\n" << DEFAULT;
		return (false);
	}
	catch(...)
	{
		std::cout << B_RED << "Exception thrown: Default exception.\n";
		return (false);
	}
	// Haven't been able to figure out, why this catch doesn't pick up on the correct exception.
	// "terminate called after throwing an instance of 'AForm::GradeTooLowException'
	//Aborted"
}

void	ShrubberyCreationForm::exec() const
{
	std::ofstream	os;
	const char		*str;

	str = getTarget().c_str();

	os.open(str);
	for (int i = 0; i < 3; i++)
	{
		os << "              * *\n           *    *  *\n"
		<< "      *  *    *     *  *\n     *     *    *  *    *\n"
		<< " * *   *    *    *    *   *\n *     *  *    * * .#  *   *\n"
		<< " *   *     * #.  .# *   *\n  *     '#.  #: #' * *    *\n"
		<< " *   * * '#. ##'       *\n   *       '###\n             '##\n"
		<< "              ##.\n              .##:\n              :###\n"
		<< "              ;###\n            ,####.\n/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\ \n\n\n";
	}
	os.close();
}