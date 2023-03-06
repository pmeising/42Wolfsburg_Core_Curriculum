/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:31:11 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:01 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << B_GREEN << "PresidentialPardonForm default constructor.\n" << DEFAULT;
}

PresidentialPardonForm::PresidentialPardonForm(std::string& target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << B_GREEN << "PresidentialPardonForm param constructor.\n" << DEFAULT;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExec())
{
	std::cout << B_GREEN << "PresidentialPardonForm copy constructor.\n" << DEFAULT;
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << B_RED << "PresidentialPardonForm destructor.\n" << DEFAULT;
}

// ######################## Operator overloads #######################

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << B_GREEN << "PresidentialPardonForm assignement operator overload.\n" << DEFAULT;
	this->_target = rhs.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

bool	PresidentialPardonForm::beSigned(const Bureaucrat& obj)
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

void	PresidentialPardonForm::exec() const
{
	std::cout << B_GREEN << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n" << DEFAULT;
}
