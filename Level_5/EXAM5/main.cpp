/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:03:19 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/04 16:10:17 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Blueprint.hpp"

int	main(void)
{
	Blueprint	A;
	Blueprint	B("Brandon");
	Blueprint	C("Branda", 1);
	Blueprint	D(C);

	std::cout << A.getName() << ": says hello as #" << A.getId() << ".\n";
	std::cout << B.getName() << ": says hello as #" << B.getId() << ".\n";
	std::cout << C.getName() << ": says hello as #" << C.getId() << ".\n";
	std::cout << D.getName() << ": says hello as #" << D.getId() << ".\n";
}
