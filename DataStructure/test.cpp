#include <iostream>

template<typename T>
class tempParent
{
	private:
		T Pdata;
	public:

};

template<typename T, typename S = char>
class tempChild : public tempParent<S>
{
	private:
		T Cdata;
	public:
};

int main()
{
	tempChild<int> a;
	return 0;
}
