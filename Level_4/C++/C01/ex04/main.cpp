/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:07:36 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/01 13:00:40 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	ft_str_replace(std::string& str, int& i, int& check, char *s1, char *s2)
{
	std::string str1 = (std::string)s1;
	std::string str2 = (std::string)s2;
	std::string	end;
	std::string	temp;
	std::string	start;

	if ((int)str2.find(str1) == -1)
	{
		int			index = str.find(str1);
		if (index == -1 || (str1 == str2))
		{
			check = -1;
			return;
		}
		else
		{
			int 		len = str1.length();
			int			rest = index + len;
			start = str.substr(0, index);
			if (rest < (int)str.length()) end = str.substr(rest);
			else end = "";
			str = start + str2 + end;
			i = start.length() + str2.length();
		}
	}
	else
	{
		// std::cout << "this is i: " << i << "\n";
		temp = &str[i];
		int			index = i + temp.find(str1);
		if (index == -1 || (str1 == str2))
		{
			check = -1;
			return;
		}
		else
		{
			int 		len = str1.length();
			int			rest = index + len;
			start = str.substr(0, index);
			if (rest < (int)str.length()) end = str.substr(rest);
			else end = "";
			str = start + str2 + end;
			i = start.length() + str2.length();
			// std::cout << index << len << rest << temp << ", " << start << ", " << end << ", " << str << "\n";
			// std::cout << "i: " << i << "\n";
		}
	}
	check++;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream	inFile;
		std::ofstream	outFile;
		std::string		ofile_name = (std::string)argv[1] + ".replace";
		std::string		str;
		int				i = 0;
		int				len = 0;
		int				check = 0;

		inFile.open((char *)(argv[1]));
		if (inFile.fail())
		{
			std::cout << "File couldn't be opened.\n";
			return (1);
		}
		outFile.open(ofile_name.c_str());
		while (true)
		{
			i = 0;
			check = 0;
			std::getline(inFile, str);
			if (inFile.fail())
			{
				std::cout << "infile couldn't read more, breaking.\n";
				break;
			}
			len = str.length();
			while (check < len && check != -1)
			{
				ft_str_replace(str, i, check, argv[2], argv[3]);
				std::cout << check << "\n";
			}
			outFile << str << "\n";
		}
		inFile.close();
		outFile.close();
	}
}
