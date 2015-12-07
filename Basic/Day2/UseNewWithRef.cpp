#include <iostream>

int main()
{
	int *ptr = new int;
	int &ref = *ptr;

	ref = 10;

	std::cout << *ptr << std::endl;

	return 0;
}
