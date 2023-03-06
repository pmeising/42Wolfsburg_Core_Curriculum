/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:35:54 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 11:24:30 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include "WrongAnimal.hpp"

class	WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(const WrongDog& obj);
		WrongDog&	operator=(const WrongDog& rhs);
		~WrongDog();
		void	makeSound() const;
};

#endif
