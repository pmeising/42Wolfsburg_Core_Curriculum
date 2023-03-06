/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:35:54 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 17:47:49 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "aAnimal.hpp"
# include "Brain.hpp"

class	Dog : public aAnimal
{
	public:
		Dog();
		Dog(const Dog& obj);
		Dog&	operator=(const Dog& rhs);
		~Dog();
		void	makeSound() const;
		void	haveThought(std::string thought);
		void	voiceThought(int i);

	private:
		Brain	*_Brain;
};

#endif
