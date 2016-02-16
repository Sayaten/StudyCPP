#include <vector>
#include <iostream>

int main()
{
	std::vector<int> a(3, 10);
	std::vector<int> b(5, 20);

	std::cout << &(a[0]) << std::hex << std::endl;
	std::cout << &(b[0]) << std::endl;

	a.swap(b);

	std::cout << &(a[0]) << std::endl;
	std::cout << &(b[0]) << std::endl;

	std::cout << std::dec << a[4] << std::endl;
	std::cout << a.size() << std::endl;
	a.pop_back();
	std::cout << std::dec << a[4] << std::endl;
	std::cout << a.size() << std::endl;

	return 0;
}

