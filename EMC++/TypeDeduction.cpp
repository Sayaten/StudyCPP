/*
	In Effective Modern C++
	About Type Deduction
	Date: 15.11.23
*/

#include <iostream>
#include <typeinfo>

#define PrintVariableName(x) {\
	std::cout << "case: " << #x << std::endl;\
}
	
template <typename T>
void CaseFirst(T& param)
{
	std::cout << "first case : " << typeid(param).name() << std::endl;
	std::cout << "address : 0x" << std::hex << &param << std::endl;
}


template<typename T>
void CaseSecond(const T& param)
{
	std::cout << "second case : " << typeid(param).name() << std::endl;
	std::cout << "address : 0x" << std::hex << &param << std::endl;
}

template<typename T>
void CaseThird(T param)
{
	std::cout << "third case : " << typeid(param).name() << std::endl;
	std::cout << "address : 0x" << std::hex << &param << std::endl;
}

int TypeDeductionMain()
{
	int x = 27;
	const int cx = x;
	const int& rx = x;

	PrintVariableName(x);
	CaseFirst(x);
	CaseSecond(x);
	CaseThird(x);
	std::cout << std::endl;
	
	PrintVariableName(cx);
	CaseFirst(cx);
	CaseSecond(cx);
	CaseThird(cx);
	std::cout << std::endl;
	
	PrintVariableName(rx);
	CaseFirst(rx);
	CaseSecond(rx);
	CaseThird(rx);
	std::cout << std::endl;

	return 0;
}
