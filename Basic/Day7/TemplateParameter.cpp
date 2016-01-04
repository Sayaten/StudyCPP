#include <iostream>

template <typename T = double, int len = 5>
class Ary
{
	private:
		T ary[len];
	public:
		Ary() { for(int i = 0 ; i < len ; ++i) { ary[i] = i; } }
		void printAry() { for(int i = 0 ; i < len ; ++i) { std::cout << ary[i] << std::endl; } }
};

int main()
{
	Ary<int, 3> obj;
	Ary<> obj1;
	obj.printAry();
	obj1.printAry();
	return 0;
}
