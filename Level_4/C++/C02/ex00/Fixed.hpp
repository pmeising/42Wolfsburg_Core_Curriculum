/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:36:14 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/27 13:03:28 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP
# include <string>
# include <iostream>

class Fixed
{
	public:
		Fixed(); // The constructor here is called without any parameter.
		Fixed(int value); // Constructor overload which accepts int input.
		Fixed(const Fixed& FPN_object); // Copy constructor is defined by using as argument a reference to an object of the same class.
		Fixed& operator=(const Fixed& rhs); // copy assignment operator 'overload' (i.e. each of those member functions here constructor, destructor and so on are overloads...). variable rhs refers to right-hand-side -> what is being passed in as an argument is the right-hand-side of the '=' statement. (fpn2 in this case ll. 23 in main.cpp).
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int					_value;
		static const int	_nbFracBits = 8;
};


#endif
