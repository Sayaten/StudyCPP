#include <iostream>
#include <cstring>

class People
{
	public:
		People(){ }
		People(int age, const char* name);
		~People(){ delete[] name; }
		int getAge(){ return age; }
		char* getName(){ return name; }
	private:
		int age;
		char* name;
};

People::People(int age, const char* name)
{
	this -> name = new char[strlen(name) + 1];
	strcpy(this -> name, name);
	this -> age = age;
}

int main()
{
	People Jisu(22, "Kim Jisu");
	std::cout << "name: " << Jisu.getName() << std::endl;
	std::cout << "age: " << Jisu.getAge() << std::endl;
	return 0;
}
