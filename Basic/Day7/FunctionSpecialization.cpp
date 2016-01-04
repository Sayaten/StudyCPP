#include <iostream>

template <typename T>
void printAdd(T param1, T param2)
{
	std::cout << param1 + param2 << std::endl; 
}

template <>
void printAdd<const char *>(const char *param1, const char *param2)
{
	std::cout << param1 << param2 << std::endl;
}

int main()
{
	printAdd(10, 20);
	printAdd("World is ", "Mine!!!");
	return 0;
}
