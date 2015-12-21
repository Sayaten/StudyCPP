#include <iostream>
#include <vector>
#include <cstring>

class Member
{
	private:
		char *name;
		int age;
	public:
		Member(const char *name = "gammaru", int age = 20) : age(age) 
		{
			this -> name = new char[strlen(name) + 1];
			strcpy(this -> name, name);
			std::cout << "Create New Member" << std::endl;
		}
		~Member() { std::cout << "Remove This Member" << std::endl; }
		int getAge() const { return age; }
		char* getName() const { return name; }
		void setAge(int age) { this -> age = age; };
		void setName(const char *name) 
		{ 
			if(name != nullptr)
			{
				delete[] name;
			}
			this -> name = new char [strlen(name) + 1]; 
			strcpy(this -> name, name);
		};
};

class Gammaru
{
	private:
		std::vector<Member> members;
	public:
		Gammaru(int size = 1) : members(size) { std::cout << "Create Gammaru" << std::endl; }
		~Gammaru() { std::cout << "Move Headquarters of Gammaru abroad" << std::endl; }
		void printAllMembers();
		void addNewMember(const char *name = "no name", int age = 0);
};
void Gammaru::printAllMembers()
{
	std::vector<Member>::iterator iter = members.begin();
	while(iter != members.end())
	{
		std::cout << iter -> getAge() << std::endl;
		std::cout << iter -> getName() << std::endl;
		++iter;
	}
}
void Gammaru::addNewMember(const char *name, int age)
{
	members.push_back(Member(name, age));
}
int main()
{
	Gammaru gammaru;
	gammaru.addNewMember("Jisu Kim", 22);
	gammaru.addNewMember("Wonyeon No", 21);
	gammaru.addNewMember("Jiyeong Choi", 21);
	gammaru.printAllMembers();
	return 0;
}


