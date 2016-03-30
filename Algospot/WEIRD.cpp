#include <iostream>
#include <vector>
#include <algorithm>

bool combination(const std::vector<int> &divisor, std::vector<int> &comb, const int &num, const int &cnt, int last, int pick);

int main()
{
	int test_case, j;
	int nums[200], divide_num, coupled_num, sum, size;
	bool not_weird;
	std::vector<int> divisor;
	std::vector<int> comb;
	std::vector<int>::iterator iter;
	std::cin >> test_case;

	for(int i = 0 ; i < test_case ; ++i)
	{
		std::cin >> nums[i];
		comb.clear();
		divisor.clear();
		sum = 1;
		not_weird = false;

		divisor.push_back(1);
		for(divide_num = 2 ; divide_num * divide_num < nums[i]; ++divide_num)
		{
			if(nums[i] % divide_num == 0) 
			{
				divisor.push_back(divide_num);
				divisor.push_back(nums[i] / divide_num);
			}
		}
		if(divide_num * divide_num == nums[i]) divisor.push_back(divide_num);

		for(iter = divisor.begin() + 1 ; iter != divisor.end() ; ++iter)
		{
			sum += *iter;
		}

		if(sum < nums[i]) 
		{
			std::cout << "not weird" << std::endl;
			continue;
		}
		std::sort(divisor.begin(), divisor.end());
		size = divisor.size();

		for(j = size ; j >= 2 ; --j)
		{
			comb.clear();
			if(combination(divisor, comb, nums[i], size, 0, j)) 
			{
				not_weird = true;
				std::cout << "not weird" << std::endl;
				break;
			}
		}
	
		if(!not_weird) std::cout << "weird" << std::endl;
	}

	return 0;
}
