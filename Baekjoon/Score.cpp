#include <iostream>

int main()
{
	int score;
	std::cin >> score;
	if(score / 90 == 1)
		std::cout << "A" << std::endl;
	else if(score / 80 == 1)
		std::cout << "B" << std::endl;
	else if(score / 70 == 1)
		std::cout << "C" << std::endl;
	else if(score / 60 == 1)
		std::cout << "D" << std::endl;
	else
		std::cout << "F" << std::endl;
	return 0;
}
