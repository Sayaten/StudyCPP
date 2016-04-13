#include <iostream>
int main()
{
	int &&a = 10;
	++a;
	std::cout << a << std::endl;
	return 0;
}
