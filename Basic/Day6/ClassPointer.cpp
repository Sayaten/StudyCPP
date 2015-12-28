#include <iostream>

class Parent
{
	private:
		int a;
	public:
		Parent(int a = 10) : a(a) {}
		void printA() { std::cout << "Parent" << std::endl; }
};

class Child : public Parent
{
	private:
		int *b;
	public:
		Child(int a = 20) : Parent(a) { b = new int[10]; }
		~Child() { std::cout << "Child destructor" << std::endl; delete[] b; }
		void printA() { std::cout << "Child" << std::endl; }
};

int main()
{
	Parent* obj1 = new Child;
	//Child* obj2 = new Child;

	obj1 -> printA();
	//obj2 -> printA();

	delete obj1;
	//delete obj2;
	return 0;
}
