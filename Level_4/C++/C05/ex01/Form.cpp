/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:27:38 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 20:42:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Bob"), _issigned(false), _gradeforsign(1), _gradeforexec(10)
{
	std::cout << B_GREEN << "Form: Default constructor.\n" << DEFAULT;
}

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name), _issigned(false), _gradeforsign(grade_sign), _gradeforexec(grade_exec)
{
	std::cout << B_GREEN << "Form: Parameter constructor.\n" << DEFAULT;
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

Form::Form(const Form& obj) : _name(obj._name), _issigned(obj._issigned), _gradeforsign(obj._gradeforsign), _gradeforexec(obj._gradeforexec)
{
	std::cout << B_GREEN << "Form: Copy-constructor.\n" << DEFAULT;
}

Form::~Form()
{
	std::cout << B_RED << "Form: Default destructor.\n" << DEFAULT;
}

// ################################ Operator overloads ########################################

Form&	Form::operator=(const Form& rhs)
{
	// std::cout << B_GREEN << "Bureaucrat: Assignment operator.\n" << DEFAULT;
	this->_issigned = rhs._issigned;
	return (*this);
}

// ############################ Member functions #############################################

std::string Form::getName(void) const
{
	return (_name);
}

bool	Form::getStatus(void) const
{
	return (_issigned);
}

unsigned int	Form::getGradeExec(void) const
{
	return (_gradeforexec);
}

unsigned int	Form::getGradeSign(void) const
{
	return (_gradeforsign);
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	return (os << obj.getName() << ", form grade needed for signature " << obj.getGradeSign() << ", grade needed for execution " << obj.getGradeExec() << ", status: " << obj.getStatus() << ".\n");
}

void	Form::beSigned(const Bureaucrat& obj)
{

	if (obj.getGrade() > this->getGradeSign())
		throw GradeTooLowException(); // is the GTLE from Form class
	else if (obj.getGrade() < 1)
		throw GradeTooHighException(); // is the GTLE from Form class
	else
	{
		this->_issigned = true;
		std::cout << B_GREEN << "Bureaucrat " << obj.getName() << " signed form " << this->getName() << " succesfully.\n" << DEFAULT;
	}
	// Haven't been able to figure out, why this catch doesn't pick up on the correct exception.
	// "terminate called after throwing an instance of 'Form::GradeTooLowException'
	//Aborted"
}


