/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:46:41 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/09 20:56:20 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

const int K = 2;

int main(int argc, char **argv)
{
	PmergeMe	obj;

	if (checkInput(argc, argv) > 0)
	{
		std::cout << B_RED << "Error: Input not correct." << DEFAULT << "\n";
		return (0);
	}
	obj.storeCollection(argc, argv);
	if (obj.checkDuplicate())
	{
		std::cout << B_RED << "Error: Input has duplicates." << DEFAULT << "\n";
		return (0);
	}
	std::cout << "Before:\t";
	for (int i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	struct timeval	start_1, end_1;
	struct timeval	start_2, end_2;
    gettimeofday(&start_1, NULL);
	obj.mergeSort(obj.getVector(), 0, obj.getVector().size() - 1);
	gettimeofday(&end_1, NULL);
	gettimeofday(&start_2, NULL);
	obj.mergeSort(obj.getDeque(), 0, obj.getDeque().size() - 1);
	gettimeofday(&end_2, NULL);
	double time_taken_1 = (end_1.tv_sec - start_1.tv_sec) + (end_1.tv_usec - start_1.tv_usec) / 1000000.0;
	double time_taken_2 = (end_2.tv_sec - start_2.tv_sec) + (end_2.tv_usec - start_2.tv_usec) / 1000000.0;
	std::cout << "After:\t";
	obj.printVector();
	std::cout << "Time to process a range of " << obj.getVector().size() << " elements with std::vector<int> : " << std::fixed << time_taken_1 * 1000000 << std::setprecision(10) << " usec\n";
	std::cout << "Time to process a range of " << obj.getDeque().size() << " elements with std::deque<int> : " << std::fixed << time_taken_2 * 1000000 << std::setprecision(10) << " usec\n";	
	return (0);
}
