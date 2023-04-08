/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:33:19 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/08 23:02:29 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <list>
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();
		
		std::vector<int>&	getInputVector();
		std::list<int>&		getInputList();
		void				addNumberToVector(int setNumberValue);
		void				addNumberToList(int setNumberValue);
		void				storeCollection(int argc,char **argv);
		void				printInputVector();
		void				printInputList();

	private:
		std::vector<int>	_inputVector;
		std::list<int>		_inputList;
};

int	check_for_not_a_digit(char *s);
int	out_of_range_number(char *s);
int	check_input_method_2(int n, char **args);
int	check_input(int argc, char **argv);

#endif
