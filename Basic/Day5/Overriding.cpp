#include <iostream>

class Animal
{
	private:
		int age;
	public:
		Animal(int age = 0) : age(age) {}
		int getAge() { return age; }
		void setAge(int age) { this -> age = age; }
		void move() { std::cout << "An animal moves" << std::endl; }
};

class Human : public Animal
{
	public:
		void move() { std::cout << "A human moves" << std::endl; }
};

int main()
{
	Human jisu;
	jisu.move();
	jisu.setAge(22);
	std::cout << jisu.getAge() << std::endl;
	return 0;
}
