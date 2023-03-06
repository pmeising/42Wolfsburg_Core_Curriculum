/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:14:03 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/26 19:32:55 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	{
		Array<char*>	string;
		Array<char*>	test(0);
		Array<int>		numbers(MAX_VAL);

		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
		}
	}

	{
		std::cout << B_GREEN << "\n##################################### Eval tests ######################################\n\n" << DEFAULT;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		// // SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << B_RED << "didn't save the same value!!" << std::endl << DEFAULT;
				return 1;
			}
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete[] mirror;
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << e.what() << ": Index out of range!\n" << DEFAULT;
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << e.what() << ": Index out of range!\n" << DEFAULT;
		}
	}
}
