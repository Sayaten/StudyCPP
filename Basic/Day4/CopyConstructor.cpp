#include <iostream>

class Copy
{
	public:
		Copy(int num) : num(num)
		{
			std::cout << "New Object: " << this <<std::endl;
		}
		Copy(const Copy& param) : num(param.getNum())
		{
			std::cout << "New Copy obj: " << this << std::endl;
		}
		~Copy()
		{
			std::cout << "Destroy obj: " << this << std::endl;
		}
		int getNum() const { return num; }
	private:
		int num;
};

Copy tempCopy(Copy param)
{
	std::cout << "Param Addr: " << &param << std::endl;
	return param;
}

int main()
{
	Copy obj(7);
	tempCopy(obj);

	std::cout << std::endl;
	Copy temp_ref = tempCopy(obj);
	std::cout << "Return Obj " << &temp_ref << std::endl;
	return 0;
}
