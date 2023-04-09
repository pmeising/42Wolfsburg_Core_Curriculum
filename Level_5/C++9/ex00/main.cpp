/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:16:35 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/09 22:17:55 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << B_RED << "Error: could not open file." << DEFAULT << "\n";
		return (0);
	}
	BitcoinExchange	btcXchange;
	btcXchange.storeDatabase((char *)"data.csv"); // "string" in C++ is considered a const std::string, need explicit conversion / type casting
	btcXchange.printBtcValue(argv[1]);
	return (0);
}
