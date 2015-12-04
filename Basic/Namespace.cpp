#include <iostream>

namespace first
{
	void printNum(int num)
	{
		std::cout << "first: " << num << std::endl;
	}
};

namespace second
{
	void printNum(int num)
	{
		std::cout << "second: " << num << std::endl;
	}

};

int main()
{
	first::printNum(10);
	second::printNum(20);
	return 0;
}
