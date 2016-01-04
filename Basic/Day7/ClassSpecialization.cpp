#include <iostream>
#include <cstring>

template <typename T>
class ClassTemp
{
	private:
		T a;
	public:
		ClassTemp(T a) : a(a) {}
		void printA() { std::cout << a << std::endl; }
};

template <>
class ClassTemp <char *>
{
	private:
		char *a;
	public:
		ClassTemp(char *a)
		{
			this -> a = new char[strlen(a) + 1];
			strcpy(this -> a, a);
		}
		void printA() { std::cout << a << std::endl; }
		~ClassTemp() { delete[] a; }
};

int main()
{
	ClassTemp<char *> a("World is Mine!!!");
	a.printA();
	return 0;
}
