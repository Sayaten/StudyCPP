#include <iostream>

int main()
{
	int *list = new int[10];
	
	std::cout << "After allocating" << std::endl;
	for(int i = 0 ; i < 10 ; ++i)
	{
		std::cout << "i: " << list[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "After insert value" << std::endl;
	for(int i = 0 ; i < 10 ; ++i)
	{
		list[i] = i;
	}

	for(int i = 0 ; i < 10 ; ++i)
	{
		std::cout << "i: " << list[i] << std::endl;
	}
	std::cout << std::endl;


	return 0;
}
