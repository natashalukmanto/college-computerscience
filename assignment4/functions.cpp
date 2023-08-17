#include "header.h"

/**
 * Recursively calculates the factorial of a number.
 *
 * @param num - The number to calculate the factorial of. Must be >= 0.
 * @return - The factorial of num. Returns 1 if num is 0.
*/
long long RecursiveFactorial(int num)
{
	if (num <= 1)
	{
		return 1;
	}
	return num * RecursiveFactorial(num - 1);
}

/** 
 * Iteratively calculates the factorial of a number.
 * 
 * @param num - The number to calculate the factorial of. Must be >= 0.
 * @return - The factorial of num. Returns 1 if num is 0.
*/
long long IterativeFactorial(int num)
{
	long long answer = 1LL;

	for (int i = num; i > 1; i--)
	{
		answer *= i;
	}

	return answer;
}

/**
 * Recursively calculates the Fibonacci number at a given position.
 * 
 * @param num - The index of the Fibonacci number to return. Must be >= 0.
 * @return - The Fibonacci number at index num.
*/
long long RecursiveFibonacci(int num)
{
	if (num <= 1)
		return num;
	return RecursiveFibonacci(num - 1) + RecursiveFibonacci(num - 2);
}

/**
 * Iteratively calculates the Fibonacci number at a given position.
 *  
 * @param num - The index of the Fibonacci number to return. Must be >= 0.
 * @return - The Fibonacci number at index num.  
*/
long long IterativeFibonacci(int num)
{

	long long a = 0;
	long long b = 1;

	if (num == 0)
		return a;
	if (num == 1)
		return b;

	long long c;
	for (int i = 2; i <= num; i++)
	{

		c = a + b;
		a = b;
		b = c;
	}

	return b;
}

// This function print heading to the console output
void PrintHeading()
{
	const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Assignment #4 - Recursion Performance";
	// OUTPUT – Class Heading
	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS"
		 << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION"
		 << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;
}