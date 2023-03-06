/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:34:47 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:24:01 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& rhs);
		~Cat();
		void	makeSound() const;
};

#endif