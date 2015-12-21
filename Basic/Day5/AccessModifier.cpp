#include <iostream>

class Base
{
	private:
		int a;
	protected:
		int b;
	public:
		Base() : a(1), b(2), c(3) {}
		int c;
};

class Derived : protected Base
{
//	public:
//		void access();
};

class Derived2 : public Derived
{
	public:
		void access2();
};
//void Derived::access()
//{
//	std::cout << "a: " << a << std::endl;
//	std::cout << "b: " << b << std::endl;
//	std::cout << "c: " << c << std::endl;
//}
void Derived2::access2()
{
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
}
int main()
{
	Derived2 obj;
	std::cout << "private: " << obj.a << std::endl;
	std::cout << "protected: " << obj.b << std::endl;
	std::cout << "public: " << obj.c << std::endl;
	return 0;
}
