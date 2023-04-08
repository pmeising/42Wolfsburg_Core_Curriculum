#include "PmergeMe.hpp"

//======== FUNCTIONS ============================================================================
int	check_for_not_a_digit(char *s)
{
	if (*s && (*s == '-' || *s == '+'))
		s++;
	while (*s)
	{
		if (isdigit(*s) != 1)
			return (1);
		s++;
	}
	return (0);
}

int	out_of_range_number(char *s)
{
	long	c;

	c = strtol(s, NULL, 10);
	if (c < MIN_INT || c > MAX_INT || strlen(s) > 11)
		return (1);
	return (0);
}

int	check_input_method_2(int n, char **args)
{
	int	i;
	int	err_1;
	int	err;

	i = 1;
	err = 0;
	while (i < n)
	{
		err_1 = check_for_not_a_digit(args[i]) + out_of_range_number(args[i]);
		err = err + err_1;
		i++;
	}
	return (err);
}

int	check_input(int argc, char **argv)
{
	int		err;

	err = 0;
	if (argc == 1)
		return(0);
	if (argc > 1)
		err = check_input_method_2(argc, argv);
	return (err);
}

// ############################## SORTING ####################################

const int K = 2;

void insertionSort(int A[], int first, int middle)
{
    for (int i = first; i < middle; i++)
    {
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > first && A[j - 1] > tempVal)
		{
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
    std::vector<int> temp(A + first, A + middle + 1);
    for (size_t i = 0; i < temp.size(); i++) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
}

// A = {5, 4, 3, 2, 1}
void merge(int A[], int first, int middle, int last)
{
	int n1 = middle - first + 1; // length of left array n1 = 3
	int n2 = last - middle; // length of right array  n2 = 2
	int LA[n1]; // declare Left Array
	int RA[n2]; // declare Right Array
	for (int i = 0; i < n1; i++) // copy values from A into LA
	{
		LA[i] = A[first + i]; // LA = {5, 4, 3}
	}
	for (int i = 0; i < n2; i++) // copy values from A into RA
	{
		RA[i] = A[middle + 1 + i]; // RA = {2, 1}
	}
	int RIDX = 0; // right index
	int LIDX = 0; // left index
	for (int i = first; i <= last; i++)
	{
		if (RIDX == n2) // reached end of right hand side Array
		{
			A[i] = LA[LIDX]; // left hand side index into A[i]
			LIDX++;
		}
		else if (LIDX == n1)
		{
			A[i] = RA[RIDX];
			RIDX++;
		}
		else if (RA[RIDX] > LA[LIDX]) // not true for RA{2} LA{5}
		{
			A[i] = LA[LIDX];
			LIDX++;
		}
		else // We are copying the SMALLEST value into A[i]
		{
			A[i] = RA[RIDX]; // A[0] = RA[0] => A = {2, 4, 3, 2, 1}
			RIDX++;
		}
	}
}

void sort(int A[], int first, int last)
{
    int n = last - first + 1;
    if (n > K) // K == 2 since we want to pair the values into sub-arrays of size 2
    {
        int middle = (first + last) / 2; // 1st. iteration q = 0 + n - 1 / 2
        sort(A, first, middle); // 2nd. sort it 0 -> middle | left hand side
        sort(A, middle + 1, last); // 3rd. it middle -> n - 1 | right hand side
        merge(A, first, middle, last);
    }
    else
        insertionSort(A, first, last);
}

// int main()
// {
// 	PmergeMe	obj;
//     // int A[] = { 10, 2, 11, 5, 12, 1, 6, 7, 3, 13, 8, 4, 9 , 13, 2 };
// 	int A[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//     int n = sizeof(A) / sizeof(A[0]);
//     // sort(A, 0, n - 1);
// 	// sort(A, 1, n - 1);
// 	sort(A, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         std::cout << A[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }


int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		PmergeMe		obj;
										// MISSING THE INPUT CHECK - Monine
		obj.storeCollection(argc, argv); // stores values in both list and vector
		std::cout << "Before: ";
		obj.printList();
		obj.sort(obj.getList().begin(), obj.getList().end());
		std::cout << "After: ";
		obj.printList();
	}
	return (0);
}