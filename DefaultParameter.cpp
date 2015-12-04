#include <iostream>

int printNum(int num = 7);
int printNums(int num1, int num2 = 10, int num3 = 30);
int main()
{
	printNum(5);
	printNum();
	printNums(5);
	return 0;
}

int printNum(int num)
{
	std::cout << "num: " << num << std::endl;
}
int printNums(int num1, int num2, int num3)
{
	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;
	std::cout << "num3: " << num3 << std::endl;
}
