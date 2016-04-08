#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[])
{
	int h, w, r;

	std::ofstream ofile("testcase.txt");
	srand((unsigned)time(NULL));

	h = std::stoi(argv[1]);
	w = std::stoi(argv[2]);

	for(int i = 0 ; i < 1 ; ++i)
	{
		//h = rand() % h + 2;
		//w = rand() % w + 2;
		ofile << h << " " << w << std::endl;

		for(int j = 0 ; j < h ; ++j)
		{
			for(int k = 0 ; k < w ; ++k)
			{
				r = rand() % 2;
				if(j == 0 || k == w - 1) r = 0;
				//if(j == 0 && k == 0 || j == h - 1 && k == w - 1) r = 0;
				ofile << r;
			}
			ofile << std::endl;
		}
	}
	ofile.close();
	return 0;
}
