/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:10:08 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/16 18:30:09 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <iostream>
# include <cstdlib>
# include <stdint.h>

typedef	struct Data
{
	int	x;
	float y;
	double z;
}				Data;

class Serializer
{
	private:
		std::string	_name;
	public:
		Serializer();
		Serializer(const Serializer& obj);
		~Serializer();
		Serializer& operator=(const Serializer& rhs);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif