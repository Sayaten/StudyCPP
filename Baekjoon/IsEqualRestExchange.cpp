#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout   << (a + b) % c << std::endl
				<< (a % c + b % c) % c << std::endl
				<< (a * b) % c << std::endl
				<< (a % c * b % c) % c << std::endl;
	return 0;
}
