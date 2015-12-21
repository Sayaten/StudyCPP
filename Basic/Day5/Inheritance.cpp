#include <iostream>

class Animal
{
	private:
		int age;
	public:
		Animal(int age = 0) : age(age) {}
		int getAge() { return age; }
		void setAge(int age) { this -> age = age; }
};

class Human : public Animal
{
	public:
		void move() { std::cout << "World is mine!!" << std::endl; }
};

int main()
{
	Human jisu;
	jisu.move();
	jisu.setAge(22);
	std::cout << jisu.getAge() << std::endl;
	return 0;
}
