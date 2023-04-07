#include "PmergeMe.hpp"

int	main()
{
	PmergeMe	obj;

	std::cout << B_BLUE << "--------------- TEST ONE: ERROR HANDLING ----------------------\n\n" << DEFAULT;
	std::cout << "Empty input. Expected Error." << std::endl;
	obj.sort("");
	std::cout << "Operator in beginning. Expected Error." << std::endl;
	obj.sort("-");
	std::cout << "Operator on 2nd. pos. Expected Error." << std::endl;
	obj.sort("2 *");
	std::cout << "Imbalance. Expected Error." << std::endl;
	obj.sort("2 2 - - +");
	std::cout << "Brackets found. Expected Error." << std::endl;
	obj.sort("2 9 * 2 (2) - -");
	std::cout << "operand over 10. Expected Error." << std::endl;
	obj.sort("5 1 20 4 - + +");

	std::cout << B_BLUE << "\n----------------------- TEST TWO: CALCULATIONS ------------------ \n\n" << DEFAULT;
	std::cout << "2.1 Expected: 8\n";
	obj.sort("2 3 2 * +");
	std::cout << "2.2 Expected: 4\n";
	obj.sort("5 1 2 4 - + +");
	std::cout << "2.3 Expected: 194\n";
	obj.sort("2 3 + 9 * 4 * 1 / 5 + 9 +");
	std::cout << "2.4 Expected: 23\n";
	obj.sort("3 2 + 2 4 5 1 2 - + * + +");
	return (0);
}
