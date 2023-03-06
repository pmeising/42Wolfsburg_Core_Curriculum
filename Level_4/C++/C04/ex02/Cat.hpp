/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:34:47 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 21:22:15 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "aAnimal.hpp"
# include "Brain.hpp"

class	Cat : public aAnimal
{
	public:
		Cat();
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& rhs);
		~Cat();
		void	makeSound() const;
		void	haveThought(std::string thought) const;
		void	voiceThought(int i) const;

	private:
		Brain	*_Brain;
};

#endif