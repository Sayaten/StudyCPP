#include <iostream>
#include <deque>

int main()
{
	std::deque<int> a(3, 100);
	std::deque<int> b(5, 200);

	std::cout << &(a[0]) << std::hex << std::endl;
	std::cout << &(b[0]) << std::endl;

	a.swap(b);

	std::cout << &(a[0]) << std::endl;
	std::cout << &(b[0]) << std::endl;

	std::cout << std::dec << a[4] << std::endl;
	std::cout << a.size() << std::endl;
	a.pop_back();
	std::cout << a[4] << std::endl;
	std::cout << a.size() << std::endl;

	return 0;
}
