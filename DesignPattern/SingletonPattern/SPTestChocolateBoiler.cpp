#include "SPChocolateBoiler.hpp"
#include <iostream>

int main()
{
	ChocolateBoiler::getInstance() -> fill();
	ChocolateBoiler::getInstance() -> boil();
	ChocolateBoiler::getInstance() -> boil();
	ChocolateBoiler::getInstance() -> drain();
	return 0;
}
