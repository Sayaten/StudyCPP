#include <iostream>

void printSum(int, int);
void printSum(double, double);

int main()
{
	printSum(10, 20);
	printSum(3.14, 2.718);
	return 0;
}

void printSum(int param1, int param2)
{
	std::cout << param1 + param2 << std::endl;
}

void printSum(double param1, double param2)
{
	std::cout << param1 + param2 << std::endl;
}
