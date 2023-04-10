/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:16:41 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 08:49:27 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>  
# include <algorithm>
# include <map>

# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

class	BitcoinExchange
{
	private:
		std::map<std::string, float>	_btcExchangeRate;
		void							checkFileCanBeOpened(std::ifstream& file);
		void							checkDateValidity(std::string date);
		float							findBtcRate(std::string date);
		std::map<std::string, float>	getExchangeRateMap();
		void    						setExchangeRate(const std::pair<std::string, float>& exchangeRate);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void							storeDatabase(char* infilePath);
		void							printBtcValue(char* infilePath);

};

void	printExchangeRate(const std::pair<std::string, float>& exchangeRate);

#endif