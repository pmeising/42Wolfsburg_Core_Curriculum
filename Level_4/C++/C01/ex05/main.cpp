/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:33:58 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/26 19:45:06 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl	Harl_2;

		Harl_2.complain(argv[1]);
	}
	else
	{
		Harl	Harl_2;
		
		Harl_2.complain("WARNING");
		Harl_2.complain("INFO");
		Harl_2.complain("WARNING");
		Harl_2.complain("WARNING");
		Harl_2.complain("DEBUG");
		Harl_2.complain("DEBUG");
		Harl_2.complain("DEBUG");
		Harl_2.complain("ERROR");
		Harl_2.complain("ERROR");
		Harl_2.complain("INFO");
		Harl_2.complain("WARNING");
		Harl_2.complain("INFO");
		Harl_2.complain("DEBUG");
		Harl_2.complain("WARNING");
		Harl_2.complain("WARNING");
		Harl_2.complain("DEBUG");
		Harl_2.complain("INFO");
		Harl_2.complain("ERROR");
	}
	return (0);
}

