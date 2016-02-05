#include <iostream>

template<typename T>
class Singleton
{
	public:
		static Singleton<T>* getInstance()
		{
			if(instance == nullptr)
			{
				std::cout << "Memory Allocation" << std::endl;
				instance = new Singleton<T>;
			}
			return instance;
		}

		static void release()
		{
			if(instance != nullptr)
			{
				std::cout << "Delete Memory" << std::endl;
				delete instance;
				instance = nullptr;
			}
		}
		void printValue();
		void setValue(T value);
		T getValue();
	private:
		Singleton() { }
		~Singleton() { }
		static Singleton<T> *instance;
		T value;
};

template<typename T>
Singleton<T>* Singleton<T>::instance = nullptr;

template<typename T>
void Singleton<T>::printValue()
{
	std::cout << "Value: " << value << std::endl;
}

template<typename T>
void Singleton<T>::setValue(T value)
{
	this -> value = value;
}

template<typename T>
T Singleton<T>::getValue()
{
	return value;
}
	
int main()
{
	if(Singleton<int>::getInstance() != nullptr)
	{
		std::cout << "Success: " << std::hex << Singleton<int>::getInstance() << std::endl;
		std::cout << "Call getInstance(): " << Singleton<int>::getInstance() << std::endl;
		std::cout << std::dec;
	}
	else
	{
		std::cout << "Fail..." << std::endl;
		return 0;
	}


	Singleton<int>::getInstance() -> setValue(5);

	std::cout << "Value: " << Singleton<int>::getInstance() -> getValue() << std::endl;
	std::cout << "Call Value(): ";
	Singleton<int>::getInstance() -> printValue();
	Singleton<int>::release();

	return 0;
}
