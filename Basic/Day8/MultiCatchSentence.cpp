#include<iostream>

void simpleFunc() throw(int, char);
void throwBoolExcept() throw();

int main()
{
	try
	{
		simpleFunc();
		throwBoolExcept();
	}
	catch(int exception)
	{
		std::cout << "int exception" << std::endl;
	}
	catch(char exception)
	{
		std::cout << "char exception" << std::endl;
	}
}

void simpleFunc() throw(int, char)
{
	int num;
	char character;
	std::cout << "num: ";
	std::cin >> num;
	
	if(num == 0)
		throw num;
	
	std::cout << "character: ";
	std::cin >> character;

	if(character == 'a')
		throw character;
}

void throwBoolExcept() throw()
{
	bool a = true;
	if(a)
		throw;
}
