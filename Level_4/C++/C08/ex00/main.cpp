/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:06:18 by pmeising          #+#    #+#             */
/*   Updated: 2023/03/02 15:40:31 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// Fills in a vector of type T with value x.
template <typename T>
void	fill_vector(std::vector<T>& vec, const T& x)
{
	for(unsigned int i = 0; i < vec.size(); i++)
		vec[i] = x;
}

template <typename T>
void	test_some_algos_vec(std::vector<T>& vector)
{
	std::cout << B_BLUE << "\n\nPrinting vector at i and replacing with rand()\n" << DEFAULT;

	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << ", ";
		vector[i] = rand();
		std::cout << B_GREEN << vector[i] << DEFAULT << ", ";
	}
	
	std::cout << B_BLUE << "\n\nAdding one value with 'push_back'\n" << DEFAULT;
	
	vector.push_back(1);
	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << ", ";
	
	std::cout << B_BLUE << "\n\nLet's sort 'em!\n" << DEFAULT;
	
	std::sort(vector.begin(), vector.end());

	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << ", ";

	std::cout << B_BLUE << "\n\nWhat about reversing?\n" << DEFAULT;

	std::reverse(vector.begin(), vector.end());

	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << ", ";
}

void	ft_vector_tests(int argc, char **argv)
{
	std::vector<int>	vector(5);

	fill_vector(vector, 4);
	std::cout << B_BLUE
	<< "Vector contains "
	<< vector.size()
	<< " values.\n"
	<< "We are interested to see where they are stored.\n"
	<< DEFAULT;
	
	for (int i = 0; i < vector.size();i++)
	{
		std::cout << vector[i] << ", ";
		std::cout << "Address: " << &vector[i] << ", ";
	}
	
	if (argc < 2)
	{
		test_some_algos_vec(vector);
	}	
	else
	{
		int i = atoi(argv[1]);
		try
		{
			::easyfind(vector, i);
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << "\n\n" << e.what() << ": Value " << i << " not in vector. " << DEFAULT << std::endl;
		}
	}
}

template <typename T>
void	test_some_algos_list(std::list<T>& list)
{
	std::list<int>::iterator itr = list.begin();
	std::cout << B_BLUE << "\n\nPrinting list at i and replacing with rand()\n" << DEFAULT;

	for (itr; itr != list.end(); itr++)
	{
		std::cout << *itr << ", ";
		*itr = rand();
		std::cout << *itr << ", ";
	}
	
	std::cout << B_BLUE << "\n\nAdding one value with 'push_back'\n" << DEFAULT;
	
	list.push_back(1);
	
	for (itr; itr != list.begin(); itr--)
		std::cout << *itr << ", ";

	for (std::list<int>::iterator itr = list.begin(); itr != list.end(); itr++)
		std::cout << *itr << ", ";

	std::cout << B_BLUE << "\n\nWhat about reversing?\n" << DEFAULT;

	std::reverse(list.begin(), list.end());

	for (std::list<int>::iterator itr = list.begin(); itr != list.end(); itr++)
		std::cout << *itr << ", ";
	std::cout << std::endl;
}

void	ft_list_tests(int argc, char **argv)
{
	std::list<int>		list;
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(-3);
	list.push_back(-4);
	list.push_back(-5);
	std::cout << B_BLUE << "\nList contains " << list.size() << " values.\n" << DEFAULT;
	
	std::cout << B_GREEN << "############################## Let's check out the list container ###########################\n" << DEFAULT;
	
	// that's how an iterator of a list is declared
	std::list<int>::iterator itr = list.begin();
	for (itr; itr != list.end(); itr++) // itr++ is overloaded to walk to the next node of the list rather then increasing the memory address.
	{
		std::cout << *itr << ", ";
		std::cout << "Address: " << &itr << ", ";
	}
	std::cout << std::endl;
	if (argc < 2)
	{
		test_some_algos_list(list);
	}
	else
	{
		int i = atoi(argv[1]);
		try
		{
			::easyfind(list, i);
		}
		catch(const std::exception& e)
		{
			std::cerr << B_RED << e.what() << ": Value " << i << " not in list. " << DEFAULT << std::endl;
		}
	}
}

int	main(int argc, char	**argv)
{
	std::cout << B_GREEN << "\n-> Let's check out the vector container\n\n" << DEFAULT;
	ft_vector_tests(argc, argv);
	std::cout << B_GREEN << "\n\n-> Let's check out the list container\n\n" << DEFAULT;
	ft_list_tests(argc, argv);
	return (0);
}
