/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:15:35 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 13:28:57 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << B_GREEN << "\nBureaucrat: Default constructor called.\n\n" << DEFAULT;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	std::cout << this->getName() << " tries to be a Bureaucrat.\n";
	try
	{
		if (grade < (unsigned int)1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > (unsigned int)150)
			throw Bureaucrat::GradeTooLowException();
		else
		{
			_grade = grade;
			std::cout << B_GREEN << "Bureaucrat: " << this->getName() << " constructed with grade: " << this->getGrade() << "\n" << DEFAULT;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << B_RED << "Exception thrown: " << e.what() << "\n" << DEFAULT;
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj.getName())
{
	std::cout << B_GREEN << "Bureaucrat: Copy constructor called.\n" << DEFAULT;
	this->_grade = obj.getGrade();
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << B_RED << "Bureaucrat: Default destructor called.\n" << DEFAULT;
}

// ############################################ Member functions ###########################################

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if ((this->getGrade() - 1) < 1)
			throw GradeTooHighException();
		else
			this->_grade = this->getGrade() - 1;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception thrown: " << e.what() << "\n";
	}
}

void	Bureaucrat::decrementGrade()
{
	std::cout << this->getName() << " tries to decrement grade.\n";
	try
	{
		if ((this->getGrade() + 1) > 150)
			throw GradeTooLowException();
		else if ((this->getGrade()) < 1)
			throw GradeTooHighException();
		else
		{
			this->_grade = this->getGrade() + 1;
			std::cout << "Decremented grade to " << this->getGrade() << "\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cout << B_RED << "Exception thrown: " << e.what() << "\n";
	}
	catch(...)
	{
		std::cout << B_RED << "Exceptoin thrown: Default exception\n";
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	// Can't assign everything, but I'll assign the non-const variables.
	// This is not a class designed to be assigned like this.
	std::cout << B_GREEN << "Bureaucrat: Assignment operator.\n" << DEFAULT;
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	return (os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n");
}

// ################################### Member functions #######################################

void	Bureaucrat::signForm(AForm& form)
{
	if (form.beSigned(*this)) // returns true if possible, false if not.
		std::cout << B_GREEN << "Bureaucrat " << this->getName() << " signed form " << form.getName() << " succesfully.\n" << DEFAULT;
	else
		std::cout << B_RED << "Bureaucrat " << this->getName() << " couldn't sign " << form.getName() << " because the Bureaucrat does not have the right grade.\n" << DEFAULT;
}

// Checks whether the form is executable from this Bureaucrat or not.
// If so, executes and outputs message; if not, writes error message to output.
void	Bureaucrat::executeForm(AForm const& form)
{
	if (form.execute(*this))
	{
		form.exec();
		std::cout << B_GREEN << this->getName() << " executed form: '" << form.getName() << "' successfully.\n" << DEFAULT;
	}
	else
		std::cout << B_RED << this->getName() << " was unable to execute the form: '" << form.getName() << ".\n" << DEFAULT;
}
