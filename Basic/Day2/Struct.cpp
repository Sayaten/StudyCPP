#include <iostream>

struct People
{
	char* getName();
	void setAge(int age);

	char *name;
	int age;
};

char* People::getName()
{
	return name;
}

void People::setAge(int age)
{
	this -> age = age;
}

int main()
{
	People *Jisu = new People[2];
	Jisu -> name = "1st Jisu";
	(Jisu + 1) -> name = "2nd Jisu";
	Jisu -> setAge(22);
	(Jisu + 1) -> setAge(21);

	std::cout << Jisu -> getName() << std::endl;
	std::cout << Jisu -> age << std::endl;
	
	std::cout << (Jisu + 1) -> getName() << std::endl;
	std::cout << (Jisu + 1) -> age << std::endl;

	return 0;
}
