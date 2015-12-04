/*
	About decaying type of auto in Effective Modern C++
	Date: 15.11.24 
*/

#include <iostream>
#include <typeinfo>

void Func(int, double);

int main()
{
	const char name[] = "World is mine";
			
	auto arr1 = name;
	auto& arr2 = name;

	auto func1 = Func;
	auto& func2 = Func;

	int x1 = 27;
	int x2(27);
	int x3 = { 27 };
	int x4{ 27 };

	auto x5 = 27;
	auto x6(27);
	auto x7 = { 27 };
	auto x8{ 27 };

	/* 
		error case
		auto x9 = {1, 2, 3.0};
	*/
	std::cout << "x1 : " << typeid(x1).name() << std::endl;
	std::cout << "x2 : " << typeid(x2).name() << std::endl;
	std::cout << "x3 : " << typeid(x3).name() << std::endl;
	std::cout << "x4 : " << typeid(x4).name() << std::endl;
	std::cout << "x5 : " << typeid(x5).name() << std::endl;
	std::cout << "x6 : " << typeid(x6).name() << std::endl;
	std::cout << "x7 : " << typeid(x7).name() << std::endl;
	std::cout << "x8 : " << typeid(x8).name() << std::endl;
}

void Func(int i_param, double d_param)
{
		std::cout << "World is mine" << std::endl;
}
