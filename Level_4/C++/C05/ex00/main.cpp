/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:01:25 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/06 17:11:03 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	Bob("Bob", 1000);
	
	Bob.decrementGrade();
	std::cout << Bob.getGrade() << "\n";
	std::cout << Bob;
	return (0);
}
