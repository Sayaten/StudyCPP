#include <iostream>

void simpleFunc();

int main()
{
	try
	{
		simpleFunc();
	}
	catch(const char *exception)
	{
		std::cout << exception << std::endl;
		//std::cout << "main(): catch exception" << std::endl;
	}
	return 0;
}

void simpleFunc()
{
	try
	{
		throw "exception";
	}
	catch(const char *)
	{
		std::cout << "simpleFunc(): catch exception" << std::endl;
		throw;
	}
}
