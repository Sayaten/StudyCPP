#include <iostream>

class People
{
	public:
		char* getName(){ return name; }
		void setName(char *name) { this -> name = name; }
		int getAge(){ return age; }
		void setAge(int age){ this -> age = age; }
	private:
		int age;
		char *name;
};

int main()
{
	People *Jisu = new People[2]();
	(Jisu[0]).setName("1st Jisu");
	(Jisu[1]).setName("2nd Jisu");
	(Jisu[0]).setAge(22);
	(Jisu[1]).setAge(21);

	std::cout << (Jisu[0]).getName() << std::endl;
	std::cout << (Jisu[0]).getAge() << std::endl;
	
	std::cout << (Jisu[1]).getName() << std::endl;
	std::cout << (Jisu[1]).getAge() << std::endl;

	return 0;
}
