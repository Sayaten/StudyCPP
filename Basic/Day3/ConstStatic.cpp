#include <iostream>

class Singleton
{
	public:
		static Singleton* getInstance()
		{
			if(instance == nullptr)
			{
				std::cout << "generate instance" << std::endl;
				instance = new Singleton();
			}
			return instance;
		}
		static Singleton* removeInstance()
		{
			if(instance != nullptr)
			{
				std::cout << "remove instance" << std::endl;
				delete instance;
				instance = nullptr;
			}
			else
			{
				std::cout << "no instance" << std::endl;
			}
		}
		const char* getString() { return str; }
		~Singleton()
		{ 
			std::cout << "call destructor" << std::endl;
		}
	private:
		Singleton() : str("World is mine!!!") { }
		static Singleton *instance;
		const char *str;
};

Singleton* Singleton::instance = nullptr;

int main()
{
	Singleton::removeInstance();
	std::cout << Singleton::getInstance() -> getString() << std::endl;
	Singleton::removeInstance();	
	return 0;
}

