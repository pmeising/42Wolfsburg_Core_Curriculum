/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:15:35 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/06 17:13:56 by pmeising         ###   ########.fr       */
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
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
		{
			_grade = grade;
			std::cout << B_GREEN << "\nBureaucrat: " << this->getName() << " constructed with grade: " << this->getGrade() << "\n\n" << DEFAULT;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception thrown: " << e.what() << "\n";
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
		std::cout << "Exception thrown: " << e.what() << "\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	return (os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n");
}
