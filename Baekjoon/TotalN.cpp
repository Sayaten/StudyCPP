#include <iostream>

int main()
{
	int n, res = 1;
	std::cin >> n;
	for(int i = 2 ; i <= n ; ++i) res += i;
	std::cout << res << std::endl;
	return 0;
}
