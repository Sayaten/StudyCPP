#include <iostream>

int main()
{
	int num = 0;
	try
	{
		while(1)
		{
			std::cout << num << " allocation" << std::endl;
			new double[100000000000000000000];
		}
	}
	catch(std::bad_alloc &exception)
	{
		std::cout << exception.what() << std::endl;
		std::cout << "Can't allocate anymore" << std::endl;
	}
	return 0;
}
