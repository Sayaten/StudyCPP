#include <iostream>

class Parent
{
	private:
	public:
		virtual void printStr() = 0;
};

class Child : Parent
{
	private:
	public:
		virtual void printStr() { std::cout << "World is Mine" << std::endl; }
};

int main()
{
	//Parent a;
	Child b;
	b.printStr();
	return 0;
}
