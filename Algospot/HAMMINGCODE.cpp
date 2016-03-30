#include <iostream>
int main()
{
	int test_case;
	char input[9];
	int check[3], data[8], error_bit;
	std::cin >> test_case;
	std::cin.ignore(1, '\n');
	for(int i = 0 ; i < test_case ; ++i)
	{
		std::cin.getline(input + 1, 8);
		for(int j = 1 ; j <= 7 ; ++j)
			data[j] = input[j] - '0';
		while(true)
		{
			check[0] = data[1] ^ data[3] ^ data[5] ^ data[7];
			check[1] = data[2] ^ data[3] ^ data[6] ^ data[7];
			check[2] = data[4] ^ data[5] ^ data[6] ^ data[7];
			error_bit = check[2] * 4 + check[1] * 2 + check[0];
			if(error_bit == 0) break;
			data[error_bit] ^= 1;
		}
		std::cout << data[3] << data[5] << data[6] << data[7] << std::endl;
	}
	return 0;
}
