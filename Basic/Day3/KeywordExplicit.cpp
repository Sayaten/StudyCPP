#include <iostream>

class Apple
{
	public:
		explicit Apple(int count = 0, const char *type = "Busa");
		~Apple() { };
		int getCount() const;
		void setCount(int count);
	private:
		int count;
		const char *type;
};

Apple::Apple(int count, const char *type) 
	: count(count), type(type)
{
}

int Apple::getCount() const
{
	return count;
}

void Apple::setCount(int count)
{
	this -> count = count;
}

int main()
{
	//Apple a(5);
	Apple a = 5;
	std::cout << a.getCount() << std::endl;
	return 0;
}
























