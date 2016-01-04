#include <iostream>

template <class T>
class SimpleTemplate
{
	private:
		T a;
		T b;
	public:
		SimpleTemplate(T a, T b);
		void printAB();
};

template <class T>
SimpleTemplate<T>::SimpleTemplate(T a, T b)
	: a(a), b(b)
{
}

template <class T>
void SimpleTemplate<T>::printAB()
{
	std::cout << a << " " << b << std::endl;
}

int main()
{
	SimpleTemplate<int> intTemp(10, 20);
	SimpleTemplate<char *> charPointerTemp("World is", "Mine!!!");

	intTemp.printAB();
	charPointerTemp.printAB();

	return 0;
}
