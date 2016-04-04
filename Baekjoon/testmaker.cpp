#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

int main()
{
	int total_case, h, w, r;
	char chars[55];
	for(int i = 0 ; i < 26 ; ++i)
	{
		chars[i] = 'A' + i;
		chars[i + 26] = 'a' + i;
	}
	chars[52] = '*';
	chars[53] = '$';
	chars[54] = '.';

	std::ofstream ofile("testcase.txt");
	srand((unsigned)time(NULL));

	total_case = rand() % 10 + 1;

	ofile << total_case << std::endl;
	for(int i = 0 ; i < total_case ; ++i)
	{
		h = rand() % 99 + 2;
		w = rand() % 99 + 2;
		ofile << h << " " << w << std::endl;

		for(int j = 0 ; j < h ; ++j)
		{
			for(int k = 0 ; k < w ; ++k)
			{
				r = rand() % 1000;
				if(r >= 52)
				{
					r = rand() % 3 + 52;
				}
				ofile << chars[r];
			}
			ofile << std::endl;
		}
	}
	ofile.close();
	return 0;
}
