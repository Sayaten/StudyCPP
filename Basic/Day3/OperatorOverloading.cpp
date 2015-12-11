#include <iostream>

class Apple
{
	public:
		Apple(int count = 0) : count(count){ }
		int operator+(Apple apple);
		int getCount() { return count; }
	private:
		int count;
};
		
int Apple::operator+(Apple apple)
{ 
	return this -> count + apple.getCount(); 
}

int main()
{
	Apple a(10);
	Apple b(20);
	std::cout << a + b << std::endl;
	return 0;
}
