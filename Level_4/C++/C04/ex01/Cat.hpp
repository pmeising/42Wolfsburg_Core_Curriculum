/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:34:47 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/09 09:42:41 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& rhs);
		virtual ~Cat();
		
		void	makeSound() const;
		void	haveThought(std::string thought) const;
		void	voiceThought(int i) const;

	private:
		Brain	*_Brain;
};

#endif