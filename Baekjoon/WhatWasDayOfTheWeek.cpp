#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> week_day{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	std::vector<int> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int mon, day, all_day;

	std::cin >> mon >> day;

	for(int i = 0 ; i < mon - 1 ; ++i)
	{
		day += days[i];
	}

	std::cout << week_day[day % 7] << std::endl;


	return 0;
}
