
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN	rpn;
		rpn.calculate(argv[1]);
	}
	return (0);
}
