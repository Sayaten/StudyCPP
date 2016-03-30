#include <iostream>
#include <array>
#include <algorithm>

int main()
{
	std::array<int, 3> i_ary;
	std::cin >> i_ary[0] >> i_ary[1] >> i_ary[2];
	std::sort(i_ary.begin(), i_ary.end());
	std::cout << i_ary[1] << std::endl;
	return 0;
}
