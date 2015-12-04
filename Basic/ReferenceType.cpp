#include <iostream>
#include <typeinfo>

void checkRef(int &param);
void checkConstRef(const int &param);
int& checkReturnRef(int &param);

int main()
{
	int variable = 10;
	int return_value;

	std::cout << "main: " << variable << std::endl;
	std::cout << "main: " << &variable << std::endl;
	checkRef(variable);
	checkConstRef(variable);
	
	return_value = checkReturnRef(variable);
	std::cout << "return reference: " << return_value << std::endl;
	int &return_value_ref = checkReturnRef(variable);
	std::cout << "return reference: " << return_value_ref << std::endl;


	return 0;
}

void checkRef(int &param)
{
	std::cout << "checkRef: " << param << std::endl;
	std::cout << "checkRef: " << &param << std::endl;
}

void checkConstRef(const int &param)
{
	std::cout << "checkConstRef: " << typeid(param).name() << std::endl;
}

int& checkReturnRef(int &param)
{
	return param;
}

/*
	wrong case:
	1) insert constant value to reference variable
	int main()
	{
		...
		int &variable = 10;
		...
	}
	2) return local variable that is reference type 
	int& returnLocalRefVariable(int param)
	{	
		int& variable = param;
		return variable; 
	}

	3) return constant value to reference variable
	int returnConstValueToRef()
	{
		return 10;
	}
	int main()
	{
		...
		int &variable = returnConstValueToRef();
		...
	}
*/
