#include <iostream>

int main()
{
	// Call RPN with:
	std::cout << "Empty input. Expected Error." << std::endl;
	rpn(NULL);
	std::cout << "Empty input. Expected Error." << std::endl;
	rpn("");
	std::cout << "Imbalance. Expected Error." << std::endl;
	rpn("9 1 8 -");
	std::cout << "Operator in beginning. Expected Error." << std::endl;
	rpn("-");
	std::cout << "Operator on 2nd. pos. Expected Error." << std::endl;
	rpn("2 *");
	std::cout << "Imbalance. Expected Error." << std::endl;
	rpn("2 2 - 1");
	std::cout << "Brackets found. Expected Error." << std::endl;
	rpn("2 9 * 2 (2) - -");
	std::cout << "operand over 10. Expected Error." << std::endl;
	rpn("5 1 20 4 - + +");
}
