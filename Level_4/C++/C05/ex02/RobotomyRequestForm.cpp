/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:18:52 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 19:30:27 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << B_GREEN << "RobotomyRequestForm default constructor.\n" << DEFAULT;
}

RobotomyRequestForm::RobotomyRequestForm(std::string& target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << B_GREEN << "RobotomyRequestForm param constructor.\n" << DEFAULT;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExec())
{
	std::cout << B_GREEN << "RobotomyRequestForm copy constructor.\n" << DEFAULT;
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << B_RED << "RobotomyRequestForm destructor.\n" << DEFAULT;
}

// ######################## Operator overloads #######################

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << B_GREEN << "RobotomyRequestForm assignement operator overload.\n" << DEFAULT;
	this->_target = rhs.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

bool	RobotomyRequestForm::beSigned(const Bureaucrat& obj)
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

void	RobotomyRequestForm::exec() const
{
	time_t	timer;
	
	std::cout << B_BLUE <<  " * . % . * Drill noise! Drill noise! Drill noise! * . % . * \n" << DEFAULT;
	if (time(&timer) % 2)
		std::cout << B_GREEN << this->getTarget() << " was robotomized succesfully!\n" << DEFAULT;
	else
		std::cout << B_RED << this->getTarget() << " could not be robotomized at this point. Please try again.\n" << DEFAULT;
}
