/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:17:53 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/16 15:49:21 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ################################### Convert from Char ##########################################

int	CharToInt(char c)
{
	int	i;

	// i = c; // This would be implicit cast from char to int.
	i = static_cast<int>(c);
	std::cout << "int:		'" << i << "'\n";
	return (i);
}

double	CharToDouble(char c)
{
	double	i;

	// i = c; // This would be implicit cast from char to int.
	i = static_cast<double>(c);
	std::cout << "double:		'" << i << "'\n";
	return (i);
}

float	CharToFloat(char c)
{
	float	i;

	// i = c; // This would be implicit cast from char to int.
	i = static_cast<float>(c);
	std::cout << "float:		'" << i << "f'\n";
	return (i);
}

// ##################################### Convert from Int #########################################

char	intToChar(int i)
{
	char	c;

	if (i < 0 || i > 255)
		std::cout << "char:		impossible\n";
	else if (i < 32 || i > 126)
		std::cout << "char:		Non displayable\n";
	else
	{
		c = static_cast<char>(i);
		std::cout << "char:		'" << c << "'\n";
	}
	return (c);
}

double	intToDouble(int i)
{
	double	d;

	d = static_cast<double>(i);
	std::cout << "double:		'" << d << "'\n";
	return (d);
}

float	intToFloat(int i)
{
	float	f;

	f = static_cast<float>(i);
	std::cout << "float:		'" << f << "f'\n";
	return (f);	
}

// ################################################# Convert from Double ###########################

char	doubleToChar(double d)
{
	char	c;

	if (d < 0 || d > 255 || d != d)
		std::cout << "char:		impossible\n";
	else if (d < 32 || d > 126)
		std::cout << "char:		Non displayable\n";
	else
	{
		c = static_cast<char>(d);
		std::cout << "char:		'" << c << "'\n";
	}
	return (c);
}

int	doubleToInt(double d)
{
	int i;

	if (d > INT_MAX || d < INT_MIN || d != d)
		std::cout << "int:		impossible\n";
	else
	{
		i = static_cast<int>(d);
		std::cout << "int:		'" << i << "'\n";
	}
	return (i);
}

float	doubleToFloat(double d)
{
	float	f;

	f = static_cast<float>(d);
	std::cout << "float:		'" << f << "f'\n";
	return (f);
}

// ############################################### Convert from Float ###################################################

char	floatToChar(float f)
{
	char	c;

	if (f < 0 || f > 255 || f != f) // comparison between f and f is only true, if the value is NaN (i.e. not a number)
		std::cout << "char:		impossible\n";
	else if (f < 32 || f > 126)
		std::cout << "char:		Non displayable\n";
	else
	{
		c = static_cast<char>(f);
		std::cout << "char:		'" << c << "'\n";
	}
	return (c);
	
}

int	floatToInt(float f)
{
	int i;

	if (f > INT_MAX || f < INT_MIN || f != f)
		std::cout << "int:		impossible\n";
	else
	{
		i = static_cast<int>(f);
		std::cout << "int:		'" << i << "'\n";
	}
	return (i);
}

double	floatToDouble(float f)
{
	double	d;

	d = static_cast<double>(f);
	std::cout << "double:		'" << d << "'\n";
	return (d);
}

int	trueType(std::string& str)
{
	int pos = str.find_first_not_of(" \t\r\n");
	std::string		str_1 = (&str[pos]);
	if (!(std::isalnum(str[pos])) && (str[pos] != '+') && (str[pos] != '-')) // is it's not alphanumeric or a plus or minus sign, it's not valid for this conversion.
		return (-1);
	if ((((!std::isalpha(str[pos])) && str_1.find('f') != std::string::npos)) || (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff"))
		return (3);
	else if (((!std::isalpha(str[pos])) && (str_1.find('.')) != std::string::npos) || (str == "nan" || str == "-inf" || str == "+inf" || str == "inf"))
		return (2);
	else if (std::isalpha(str[pos]))
		return (0);
	else
		return (1);
}

void	ScalarConverter::convert(std::string str)
{
	std::cout.precision(16);
	std::string		type[4] = {"char", "int", "double", "float"}; // 0 = char 1 = int 2 = double 3 = float
	int		true_type;
	true_type = trueType(str);
	switch (true_type)
	{
		case 0:
		{
			char c = str[0];
			std::cout << "char:		'" << c << "'\n";
			CharToInt(c);
			CharToFloat(c);
			CharToDouble(c);
			break;
		}
		case 1:
		{
			int i = atoi(str.c_str());
			intToChar(i);
			std::cout << "int:		'" << i << "'\n";
			intToFloat(i);
			intToDouble(i);
			break;
		}
		case 2:
		{
			double d = atof(str.c_str());
			doubleToChar(d);
			doubleToInt(d);
			doubleToFloat(d);
			std::cout << "double:		'" << d << "'\n";
			break;
		}
		case 3:
		{
			float f = atof(str.c_str());
			floatToChar(f);
			floatToInt(f);
			std::cout << "float:		'" << f << "f'\n";
			floatToDouble(f);
			break;
		}
		default:
			break;
	}
}
