#include "RPN.hpp"

int main()
{
	// Call RPN with:
	RPN	rpn;
	std::cout << "Empty input. Expected Error." << std::endl;
	rpn.calculate("");
	std::cout << "Imbalance. Expected Error." << std::endl;
	rpn.calculate("9 1 8 -");
	std::cout << "Operator in beginning. Expected Error." << std::endl;
	rpn.calculate("-");
	std::cout << "Operator on 2nd. pos. Expected Error." << std::endl;
	rpn.calculate("2 *");
	std::cout << "Imbalance. Expected Error." << std::endl;
	rpn.calculate("2 2 - 1");
	std::cout << "Brackets found. Expected Error." << std::endl;
	rpn.calculate("2 9 * 2 (2) - -");
	std::cout << "operand over 10. Expected Error." << std::endl;
	rpn.calculate("5 1 20 4 - + +");
}
