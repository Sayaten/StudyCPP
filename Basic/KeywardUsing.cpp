#include <iostream>

using std::cout;
using std::endl;

namespace first
{
	void printNum(int param)
	{
		cout << "param: " << param << endl;
	}
}

using namespace first;

int main()
{
	printNum(10);
	return 0;
}
