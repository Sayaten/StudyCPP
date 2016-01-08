#include<iostream>

void simpleFunc1();
void simpleFunc2();
void simpleFunc3();

int main()
{
	try
	{
		simpleFunc1();
	}
	catch(int exception)
	{
		std::cout << "main: " <<  exception << std::endl;
	}
	return 0;
}

void simpleFunc1()
{
	try
	{
		simpleFunc2();
	}
	catch(bool exception)
	{
		std::cout << "simpleFunc1(): " <<  exception << std::endl;
	}
}
void simpleFunc2()
{
	try
	{
		simpleFunc3();
	}
	catch(char exception)
	{
		std::cout << "simpleFunc2(): " <<  exception << std::endl;
	}
}
void simpleFunc3()
{
	int num1 = 0;
	if(num1 == 0)
		throw num1;
}
