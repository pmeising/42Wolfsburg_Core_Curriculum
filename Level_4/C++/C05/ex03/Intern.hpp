/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:40:11 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 20:02:03 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& rhs);
		~Intern();
		
		void	hm() const;
		AForm	*makeForm(std::string formName, std::string formTarget);
};

#endif