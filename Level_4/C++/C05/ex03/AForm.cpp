/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:27:38 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/07 10:45:22 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _issigned(false), _gradeforsign(1), _gradeforexec(1)
{
	std::cout << B_GREEN << "AForm: Default constructor.\n" << DEFAULT;
}

AForm::AForm(std::string name, int grade_sign, int grade_exec) : _name(name), _issigned(false), _gradeforsign(grade_sign), _gradeforexec(grade_exec)
{
	std::cout << B_GREEN << "AForm: Parameter constructor.\n" << DEFAULT;
	try
	{
		if (this->getGradeExec() < 1 || this->getGradeSign() < 1)
			throw GradeTooHighException();
		else if (this->getGradeExec() > 150 || this->getGradeSign() > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << B_RED << "Exception thrown: " << e.what() << "\n" << DEFAULT;
	}
}

AForm::AForm(const AForm& obj) : _name(obj._name), _issigned(obj._issigned), _gradeforsign(obj._gradeforsign), _gradeforexec(obj._gradeforexec)
{
	std::cout << B_GREEN << "AForm: Copy-constructor.\n" << DEFAULT;
}

AForm::~AForm()
{
	std::cout << B_RED << "AForm: Default destructor.\n" << DEFAULT;
}

// ################################ Operator overloads ########################################

AForm&	AForm::operator=(const AForm& rhs)
{
	// std::cout << B_GREEN << "Bureaucrat: Assignment operator.\n" << DEFAULT;
	this->_issigned = rhs._issigned;
	return (*this);
}

// ############################ Member functions #############################################

std::string AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getStatus(void) const
{
	return (_issigned);
}

unsigned int	AForm::getGradeExec(void) const
{
	return (_gradeforexec);
}

unsigned int	AForm::getGradeSign(void) const
{
	return (_gradeforsign);
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	return (os << obj.getName() << ", form grade needed for signature " << obj.getGradeSign() << ", grade needed for execution " << obj.getGradeExec() << ", status: " << obj.getStatus() << ".\n");
}

void	AForm::sign()
{
	this->_issigned = true;
}

bool	AForm::execute(Bureaucrat const& executor) const
{
	if (this->getStatus())
	{
		try
		{
			if (executor.getGrade() > this->getGradeExec())
				throw GradeTooLowException();
			else
				return (true);
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception thrown: " << e.what() << "\n";
		}
		catch(...)
		{
			std::cout << "Exception thrown: Default\n";
		}
	}
	else
		return (false);
	return (false);
}
