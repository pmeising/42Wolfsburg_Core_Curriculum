/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:25:32 by pmeising          #+#    #+#             */
/*   Updated: 2023/03/02 17:03:33 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	setrand(int &a)
{
	a = rand();
}

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try
		{
			sp.addNumber(19);
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << e.what() << " Maximum storage reached.\n" << DEFAULT;
		}
		try
		{
			std::cout << "\nShortest span is: " << sp.shortestSpan() << "."<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << e.what() << " Logically not possible\n" << DEFAULT;
		}
		try
		{
			std::cout << "\nLongest span is: " << sp.longestSpan() << "." << std::endl;			
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << e.what() << " Logically not possible\n" << DEFAULT;
		}
	}
	{
		Span	sp(20000);
		Span	sp_2 = sp;
		sp.addNumber(3);
		std::vector<int> vec = sp.get_vec();
		std::vector<int> vec_2 = sp_2.get_vec();
		std::cout << vec[0] << "\n";
		std::cout << vec_2[0] << "\n";
	}
	{
		Span	sp(100);
		std::vector<int>	test(5);
		for(unsigned int i = 0; i < 5; i++)
			test[i] = 1;
		std::vector<int>	vec = sp.get_vec();
		std::for_each(vec.begin(), vec.end(), setrand);
		for(unsigned int i = 0; i < vec.size(); i++)
			std::cout << vec[i] << ", ";
		vec.insert(vec.end(),  test.begin(), test.end());
		for(unsigned int i = 0; i < vec.size(); i++)
			std::cout << vec[i] << ", ";

		try
		{
			std::cout << "\nLongest span: " << sp.longestSpan() << "\n";		
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << e.what() << " Logically not possible\n" << DEFAULT;
		}
		try
		{
			std::cout << "\nShortest span: " << sp.shortestSpan() << "\n";		
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << e.what() << " Logically not possible\n" << DEFAULT;
		}
	}
	return 0;
}