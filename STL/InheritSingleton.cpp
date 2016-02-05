#include <iostream>

template <typename T>
class Singleton
{
	public:
		static T* getInstance()
		{
			if(instance == nullptr)
			{
				instance = new T;
			}
			return instance;
		}
		static void release()
		{
			if(instance != nullptr)
			{
				delete instance;
				instance = nullptr;
			}
		}
		Singleton() { }
		virtual ~Singleton() { }
	private:
		static T* instance;
};

template <typename T>
T* Singleton<T>::instance = nullptr;

class SingletonOBJ : public Singleton<SingletonOBJ>
{
	public:
		SingletonOBJ() { }
		~SingletonOBJ() { }
		void setValue(int value) { this -> value = value; }
		int getValue() { return value; }
	private:
		int value;
};

int main()
{
	SingletonOBJ *obj1 = SingletonOBJ::getInstance();
	SingletonOBJ *obj2 = SingletonOBJ::getInstance();

	obj1 -> setValue(10);

	std::cout << obj1 -> getValue() << std::endl;
	std::cout << obj2 -> getValue() << std::endl;

	obj1 -> release();

	return 0;
}
