/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:35:54 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:24:30 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& obj);
		Dog&	operator=(const Dog& rhs);
		~Dog();
		void	makeSound() const;
};

#endif
