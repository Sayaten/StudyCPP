#include "SPChocolateBoiler.hpp"
#include <iostream>

using namespace std;

ChocolateBoiler* ChocolateBoiler::instance = nullptr;

ChocolateBoiler::ChocolateBoiler()
{
	empty = true;
	boiled = false;
}

void ChocolateBoiler::fill()
{
	if(isEmpty())
	{
		cout << "fill" << endl;
		empty = false;
		boiled = false;
	}
}
void ChocolateBoiler::drain()
{
	if (!isEmpty() && isBoiled())
	{
		cout << "drain" << endl;
		empty = true;
	}
}
void ChocolateBoiler::boil()
{
	if (!isEmpty() && !isBoiled())
	{
		cout << "boil" << endl;
		boiled = true;
	}
}
bool ChocolateBoiler::isEmpty()
{
	return empty;
}
bool ChocolateBoiler::isBoiled()
{
	return boiled;
}
