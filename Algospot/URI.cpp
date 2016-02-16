#include <iostream>
#include <cstring>

int main()
{
	int test_case, str_len, nums[2];
	char str[101], special_char;

	std::cin >> test_case;

	for(int i = 0 ; i < test_case ; ++i)
	{
		std::cin >> str;
		str_len = strlen(str);
		for(int j = 0 ; j < str_len ; ++j)
		{
			if(str[j] == '%')
			{
				// '0' == 48	'a' == 97
				nums[0] = (str[j + 1] < 'a') ? (str[j + 1] - '0') * 16 : (str[j + 1] - 87) * 16;
				nums[1] = (str[j + 2] <= '9') ? (str[j + 2] - '0') : (str[j + 2] - 87);
				special_char = nums[0] + nums[1];
				std::cout << special_char;
				j += 2;
			}	
			else
			{
				std::cout << str[j];
			}
		}
		std::cout << std::endl;
	};
	return 0;
}
