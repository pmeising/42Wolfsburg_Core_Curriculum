/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:16:30 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/16 14:50:02 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <limits.h>


// Misleading subject pdf. A static class itself does not exist.

class	ScalarConverter
{
	public:
		static void	convert(std::string str);
	
	private:
		// ScalarConverter();
		// ScalarConverter(const ScalarConverter& obj);
		// ScalarConverter& operator=(const ScalarConverter& rhs);
		// ~ScalarConverter();
};

#endif