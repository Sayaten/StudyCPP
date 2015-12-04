/*
	In Effective Modern C++
	About Array Argument
	Date: 15.11.23
*/

#include <iostream>
#include <typeinfo>

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

template<typename T, std::size_t N>
void CaseThird(T (&param)[N])
{
	std::cout << "third case : " << typeid(param).name() << std::endl;
	std::cout << "address : 0x" << std::hex << &param << std::endl;
}

int ArrayArgumentMain()
{
	const char test_string[] = "Hello World!";

	CaseFirst(test_string);
	CaseSecond(test_string);
	CaseThird(test_string);
	return 0;
}
