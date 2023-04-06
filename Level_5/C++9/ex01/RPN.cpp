/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:51:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/06 21:33:31 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN&	obj)
{
	this->_input = obj._input;
	this->_result = obj._result;
	this->_A = obj._A;
	this->_B = obj._B;
}

RPN& RPN::operator=(const RPN& rhs)
{
	this->_input = rhs._input;
	this->_result = rhs._result;
	this->_A = rhs._A;
	this->_B = rhs._B;
	return (*this);
}

int	RPN::calculate(const std::string input)
{
	if (this->inputCheck(input) == -1)
		return;
}

int	RPN::inputCheck(const std::string input)
{
	int	size = input.size();
	for (int i = 0; i < size; i++)
		if ((input[i] >= '0' && input[i] <= '9') || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			if (i < (size -1) && input[i + 1] != ' ')
			{
				std::cout << "Error\n";
				return (-1);
			}
		else if (input[i] != ' ')
		{
			std::cout << "Error\n";
			return (-1);
		}
	if (input.empty())
	{
		std::cout << "Error\n";
		return (-1);
	}
	else if (input.find("(") != std::string::npos || input.find(")") != std::string::npos) // If bracket is found
	{
		std::cout << "Error\n";
		return (-1);
	}
	int count_a = 0;
	int count_b = 0;
	for (int i = 0; i < size; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			count_a++;
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			count_b++;
		if (count_b > count_a && count_a < 2)
		{
			std::cout << "Error\n";
			return (-1);
		}
	}
	if (count_b >= count_a)
	{
		std::cout << "Error\n";
		return (-1);
	}
}