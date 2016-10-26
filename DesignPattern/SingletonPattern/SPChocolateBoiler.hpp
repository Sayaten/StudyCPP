#ifndef __SP_CHOCOLATE_BOILER_HPP__
#define __SP_CHOCOLATE_BOILER_HPP__

#include <iostream>

using namespace std;

class ChocolateBoiler
{
	public:
		void fill();
		void drain();
		void boil();
		bool isEmpty();
		bool isBoiled();
		static ChocolateBoiler* getInstance()
		{
			if(instance == nullptr)
			{
				cout << "initiate boiler" << endl;
				instance = new ChocolateBoiler();
			}
			return instance;
		}
	private:
		ChocolateBoiler();
		bool empty;
		bool boiled;
		static ChocolateBoiler* instance;
};

#endif
