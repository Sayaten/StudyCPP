#include <iostream>

int main()
{
	int num1, num2;
	std::cout << "num1 : ";
	std::cin >> num1;
	std::cout << "num2 : ";
	std::cin >> num2;
	try
	{
		if(num2 == 0)
			throw num2;
		std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
	}
	catch(int exception)
	{
		std::cout << exception << " is not valid number" << std::endl;
	}
	return 0;
}
