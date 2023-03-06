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
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& FPN_object);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Calculation operator overloads
		bool	operator>(const Fixed& a);
		bool	operator<(const Fixed& a);
		bool	operator>=(const Fixed& a);
		bool	operator<=(const Fixed& a);
		bool	operator==(const Fixed& a);
		bool	operator!=(const Fixed& a);
		Fixed	operator+(const Fixed& a);
		Fixed	operator-(const Fixed& a);
		Fixed	operator*(const Fixed& a);
		Fixed	operator/(const Fixed& a);
		Fixed	operator++(int);
		Fixed	operator++(void);
		Fixed	operator--(int);
		Fixed	operator--(void);
		static Fixed	max(Fixed& a, Fixed& b);
		static Fixed	min(Fixed& a, Fixed& b);
		static Fixed	max(const Fixed& a, const Fixed& b);
		static Fixed	min(const Fixed& a, const Fixed& b);


	private:
		int					_value;
		static const int	_nbFracBits = 8;
};

std::ostream& operator<<(std::ostream &stream, const Fixed& out);

#endif
