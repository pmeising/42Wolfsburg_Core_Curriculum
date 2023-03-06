/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:10:20 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:43:58 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal&	operator=(const WrongAnimal& rhs);
		~WrongAnimal();
		void	setType(const std::string& type);
		std::string	getType(void) const;
		void	makeSound() const;

	protected:
		std::string	_type;
};

// The virtual keyword here created a V-Table which contains a list of 
// all virtual functions of our base class to be able to map them to the overwritten
// functions of the derived classes at RUNTIME.

#endif