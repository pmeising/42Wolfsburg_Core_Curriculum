/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:08 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/16 18:32:40 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		data;
	Data		*ptr;
	uintptr_t	ui;

	ptr = &data;
	std::cout << "Ptr address: " << ptr << ".\n";
	ui = Serializer::serialize(ptr);
	ptr = Serializer::deserialize(ui);
	std::cout << "unigned int: " << ui << ".\n"
	<< "ptr address: " << ptr << ".\n";
}
