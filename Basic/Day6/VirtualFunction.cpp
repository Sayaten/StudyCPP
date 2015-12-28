#include <iostream>

class Parent
{
	private:
	public:
		virtual ~Parent() { std::cout << "Parent Destructor" << std::endl; }
		virtual void virtualFunc() { std::cout << "Virtual Parent" << std::endl; }
		void noVirtualFunc() { std::cout << "No Virtual Parent" << std::endl; }
};

class Child : public Parent
{
	private:
	public:
		virtual ~Child() { std::cout << "Child Destructor" << std::endl; }
		virtual void virtualFunc() { std::cout << "Virtual Child" << std::endl; }
		void noVirtualFunc() { std::cout << "No Virtual Child" << std::endl; }
};

int main()
{
	Parent *obj = new Child;

	obj -> virtualFunc();
	obj -> noVirtualFunc();

	delete obj;
	return 0;
}
