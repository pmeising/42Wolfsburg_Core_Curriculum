/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:16:46 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/10 09:14:55 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() :
	_btcExchangeRate(std::map<std::string, float>())
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		new (this) BitcoinExchange(src);
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::setExchangeRate(const std::pair<std::string, float>& setExchangeRate)
{
	this->_btcExchangeRate.insert(setExchangeRate);
}

std::map<std::string, float>	BitcoinExchange::getExchangeRateMap()
{
	return _btcExchangeRate;
}

/*
*	Check if file can be opened.
*/
void	BitcoinExchange::checkFileCanBeOpened(std::ifstream& file)
{
	if (!file.is_open())
		std::cout << B_RED << "Error: file could not be opened" << DEFAULT << "\n";
}

/*
*	Goes through csv. file and stores the database in a map.
*	ll. 75 increases plus 1 in order to skip the ",".
*/
void	BitcoinExchange::storeDatabase(char* infilePath)
{
	std::ifstream	infile(infilePath);
	checkFileCanBeOpened(infile);
	std::string	line;
	std::getline(infile, line);
	while(getline(infile, line))
	{
		size_t	pos = line.find(",");
		if (pos == std::string::npos)
		{
			std::cout << "Error: delimiter not found in line \"" << line << "\"" << std::endl;
			continue;
		}
		std::string	date = line.substr(0, pos);
		std::string	numericValue = line.substr(pos + 1);
		float btcNumericValueInt = static_cast<float>(atof(numericValue.c_str()));
		this->_btcExchangeRate.insert(std::pair<std::string, float > (date, btcNumericValueInt));
	}
	infile.close();
}

/*
*	Input: date in format "YYYY-MM-DD"
*	Return: bitcoin rate as float.
*	iterates through map and finds date.
*	If date non-existent, falls back onto the prior date.
*	->first and ->second refer to the first and second key of the map values.
*	Since the map stores a key-value pair, it can retrieve these values using the -> first ->second operators.
*/
float	BitcoinExchange::findBtcRate(std::string date)
{
	float		btcCoinRate = 0;
	bool		dateFound = false;
	std::string	closestEarlierDate;
	float		closestEarlierRate = 0;
	std::map<std::string, float>::const_iterator it; // declare a const_iterator for the map

	for (it = _btcExchangeRate.begin(); it != _btcExchangeRate.end(); it++)
	{
		if (it->first < date) // check if the current date in the map is earlier than the desired date
		{
			if (closestEarlierDate.empty() || closestEarlierDate < it->first) // check if this date is closer than the previously found closest date
			{
				closestEarlierDate = it->first;
				closestEarlierRate = it->second;
			}
		}
		else if (it->first == date)
		{
			btcCoinRate = it->second;
			dateFound = true;
			break;
		}
	}
	if (dateFound == false)
	{
		if (!closestEarlierDate.empty())
			btcCoinRate = closestEarlierRate;
		else
			btcCoinRate = 0;
	}
	return (btcCoinRate);
}


/*
*	This is where the operations take place, each line is being 
*	read in and then input checked.
*	First line is skipped as it is the header of the file.
*	If input is correct, the value is calculated and printed, if not
*	Error is thrown.
*/
void	BitcoinExchange::printBtcValue(char* infilePath)
{
	std::ifstream infile(infilePath);
	checkFileCanBeOpened(infile);
	std::string	line;
	std::getline(infile, line);
	while(getline(infile, line))
	{
		const std::string& delimiter = " | ";
		size_t	pos = line.find(delimiter);
		if (pos == std::string::npos)
		{
			std::cout << B_RED << "Error: bad input => " << line << DEFAULT << "\n";
			continue;
		}
		std::string date = line.substr(0, pos);
		if (checkDateValidity(date) == -1)
		{
			std::cout << B_RED << "Error: date invalid => " << line << DEFAULT << "\n";
			continue;
		}
		std::string btcCoinsNumber = line.substr(pos + delimiter.length());

		float btcCoinsNumberInt = static_cast<float>(atof(btcCoinsNumber.c_str()));
		if (btcCoinsNumberInt < 0)
		{
			std::cout << B_RED << "Error: not a positive number." << DEFAULT << "\n";
			continue;
		}
		if (static_cast<long>(btcCoinsNumberInt) > static_cast<long>(MAX_INT))
		{
			std::cout << B_RED << "Error: too large a number." << DEFAULT << "\n";
			continue;
		}
		float btcCoinRate = 0;
		btcCoinRate = findBtcRate(date);
		std::cout << date << " => " << btcCoinsNumberInt << " = " << static_cast<float>(btcCoinsNumberInt * btcCoinRate) << "\n";
	}
	infile.close();
}

/*
*	Input: Date in format "YYYY-MM-DD"
*	Return: Invalid date -> -1. Valid date -> 0.
*	Splits date into year, month and day and sets limits (2023, 12 and 31).
*/
int	BitcoinExchange::checkDateValidity(std::string date)
{
	std::string	month = date.substr(5);
	std::string	day = month.substr(3);
	if (date > "2023" || month > "12" || day > "31")
		return (-1);
	return (0);
}

/*
*	Simply prints the values for the exchange rate using first-> and second->.
*/
void	printExchangeRate(const std::pair<std::string, float>& exchangeRate)
{
	std::cout << exchangeRate.first << " , " << exchangeRate.second << "\n";
}