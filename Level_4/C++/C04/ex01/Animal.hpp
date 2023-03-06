/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:10:20 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/09 09:41:47 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

class	Animal
{
	public:
		Animal();
		Animal(const Animal& obj);
		Animal&	operator=(const Animal& rhs);
		virtual ~Animal();
		
		void	setType(const std::string& type);
		std::string	getType(void) const;
		virtual void	makeSound() const;

	protected:
		std::string	_type;
};

// A class becomes an abstract class, if it has at least 1 pure virtual function.
// A pure virtual function is declared as follows:
//		virtual void	makeSound() const =0;
// the =0; is all it takes to make it pure virtual. There does not need to be an implementation provided for this function definition.

// An abstract class can not be instantiated. Only a derived class of such a class can be used. Ever.

// The virtual keyword here created a V-Table which contains a list of 
// all virtual functions of our base class to be able to map them to the overwritten
// functions of the derived classes at RUNTIME.

#endif