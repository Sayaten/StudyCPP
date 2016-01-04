#include <iostream>

template <typename T1, typename T2>
void output(T1 a, T2 b)
{
	std::cout << a << b << std::endl;
}

template <typename T1, int>
void output(T1 a, int b)
{
	for(int i = 0 ; i < b ; ++i)
		std::cout << a << std::endl;
}

int main()
{
	output("Hello", 5);
	return 0;
}
