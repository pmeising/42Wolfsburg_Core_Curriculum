/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:51:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/07 09:17:08 by pmeising         ###   ########.fr       */
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
	this->_A = obj._A;
	this->_B = obj._B;
}

RPN& RPN::operator=(const RPN& rhs)
{
	this->_input = rhs._input;
	this->_A = rhs._A;
	this->_B = rhs._B;
	return (*this);
}

// #################### MEMBER FUNCTIONS ############################

/*
*	Input: std::string input string.
*	Returns: result of RPN calculation as 'int'.
*
*	1. checks, whether input string is valid.
*	2. copies input string into _input.
*	3. iterates through _input and pushes numbers to _A,
*	operators to _B, skips spaces.
*	4. If operate returns 0, keep iterating and print result.
*/
int	RPN::calculate(const std::string input)
{
	if (this->inputCheck(input) == -1)
		return (0);
	this->_input = input;
	int i = 0;
	while (this->_input[i])
	{
		// std::cout << "Input[" << i << "]: " << this->_input[i] << "\n";
		if (this->_input[i] >= '0' && this->_input[i] <= '9')
		{
			std::cout << ((int)this->_input[i] - 48) << "\n";
			this->_A.push(((int)this->_input[i] - 48));
		}
		else if (this->_input[i] != ' ')
			this->_B.push(this->_input[i]);
		// std::cout << "Top A: " << this->_A.top() << "\n";
		if (!this->_A.empty() && !this->_B.empty())
			if (this->operate() == -1)
				return (0);
		i++;
	}
	this->printResult();
	return (this->_A.top());
}


/*
*	Input: non
*	Return: -1 for error, 0 for success
*	1. checks if operation is viable.
*	2. Assignes both operands to the corresponding
*	variable and removes values from Stack (i.e. pop()).
*	3. Calculates result and adds it to stack.
*	4. Removes operator from stack _B.
*/
int	RPN::operate()
{
	if (_A.size() < 2)
	{
		std::cout << "Error\n";
		return (-1);
	}
	int	second_op = (int)this->_A.top();
	this->_A.pop();
	int	first_op = (int)this->_A.top();
	this->_A.pop();
	if (this->_B.top() == '+')
	{
		this->_A.push(first_op + second_op);
		this->_B.pop();
	}
	else if (this->_B.top() == '-')
	{
		this->_A.push(first_op - second_op);
		this->_B.pop();
	}
	else if (this->_B.top() == '*')
	{
		this->_A.push(first_op * second_op);
		this->_B.pop();
	}
	else if (this->_B.top() == '/')
	{
		this->_A.push(first_op / second_op);
		this->_B.pop();
	}
	return (0);
}

void	RPN::printResult()
{
	std::cout << (this->_A.top()) << std::endl;
}


/*
*	Input: string to check.
*	Return:	-1 for error, 0 for success.
*	Is intended to filter out the following erroneous inputs:
*	"", "9 1 8 -", "-", "2 2 - 1", "2 9 * 2 (2) - -" and "5 1 20 4 - + +".
*/
int	RPN::inputCheck(const std::string input)
{
	int	size = input.size();
	for (int i = 0; i < size; i++)
		if ((input[i] >= '0' && input[i] <= '9') || (input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
		{
			if (i < (size -1) && input[i + 1] != ' ')
			{
				std::cout << "Error\n";
				return (-1);
			}
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
	return (0);
}