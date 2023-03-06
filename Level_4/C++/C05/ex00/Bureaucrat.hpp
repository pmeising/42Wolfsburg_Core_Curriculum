/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:00:58 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/06 17:04:49 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <exception>

# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		
		~Bureaucrat();
		std::string	getName(void) const;
		unsigned int	getGrade(void) const;
		void	incrementGrade();
		void	decrementGrade();

	class GradeTooHighException : public std::exception // This class is inherited from the  base class Exception. Now the Exception base class has a member function called 'what'. This needs to be overwritten by our own what function.
	{
		// the 'what' function is declared in the exception.h file as: 'virtual const char *std::exception::what() const'
		virtual const char *what() const throw()
		{
			return ("The Grade is too high, maximum grade achievable: 1");
		}
	};
	class GradeTooLowException : public std::exception
	{
		// NEed to implement the what function.
		// the 'what' function is declared in the exception.h file as: 'virtual const char *std::exception::what() const'
		virtual const char *what() const throw()
		{
			return ("The Grade is too low, minimum grade possible: 150");
		}
	};
	
	private:
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

// All about the 'what' function in each exception derived class and the use of the throw() keyword. https://learn.microsoft.com/en-us/cpp/cpp/exception-specifications-throw-cpp?source=recommendations&view=msvc-170
// In short: The throw() is required to tell the compiler that this function does not throw an exception.

#endif
