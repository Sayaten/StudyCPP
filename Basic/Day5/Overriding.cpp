#include <iostream>

class Animal
{
	friend class Human;
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
		int move() { std::cout << "A human moves" << std::endl; return 0; }
};

int main()
{
	Human jisu;
	jisu.move();
	jisu.setAge(22);
	std::cout << jisu.getAge() << std::endl;
	return 0;
}
