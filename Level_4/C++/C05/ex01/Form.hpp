/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:06:33 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 20:46:30 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat; // Pre-declaring the class Bureaucrat. Tells the compiler: 
// Look this class exists, but only comes up later on in the code, so don't sweat it. :D 

class	Form
{
	private:
		const std::string	_name;
		bool				_issigned;
		const unsigned int	_gradeforsign;
		const unsigned int	_gradeforexec;
	
	public:
		Form();
		Form(std::string name, int grade_sign, int grade_exec);
		Form(const Form& obj);
		Form& operator=(const Form& rhs);
		~Form();

		std::string		getName(void) const;
		bool			getStatus() const;
		unsigned int	getGradeSign() const;
		unsigned int	getGradeExec() const;
		void			beSigned(const Bureaucrat& obj);

	class GradeTooHighException : public std::exception
	{
		// Research this throw()
		virtual const char *what() const throw()
		{
			return ("The Grade is too high, maximum grade achievable: 1");
		}
	};
	class GradeTooLowException : public std::exception
	{
		// Research this throw()
		virtual const char *what() const throw()
		{
			return ("The Grade is too low, minimum grade required: 150");
		}
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
