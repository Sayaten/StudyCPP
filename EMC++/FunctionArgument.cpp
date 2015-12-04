/*
	In Effective Modern C++
	About Array Argument
	Date: 15.11.23
*/

#include <iostream>
#include <typeinfo>
void TestFunction(int i_param, double d_param)
{
	std::cout << "Hello World!" << std::endl;
}

template<typename T>
void CaseFirst(T param)
{
	std::cout << "first case : " << typeid(param).name() << std::endl;
	std::cout << "address : 0x" << std::hex << &param << std::endl;
}

template<typename T>
void CaseSecond(T& param)
{
	std::cout << "second case : " << typeid(param).name() << std::endl;
	std::cout << "address : 0x" << std::hex << &param << std::endl;
}

int FunctionArgumentMain()
{
	CaseFirst(TestFunction);
	CaseSecond(TestFunction);
	return 0;
}
