#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	for(int i = 1 ; i <= 9 ; ++i)
		std::cout << n << " * " << i << " = " << i * n << std::endl;
	return 0;
}
