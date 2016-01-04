#include <iostream>

template <typename T>
T add(T param1, T param2)
{
	return param1 + param2;
}

template <class T>
T minus(T param1, T param2)
{
	return param1 - param2;
}

int main()
{
	std::cout << add(10, 20) << std::endl;
	std::cout << minus(10, 20) << std::endl;
	return 0;
}
