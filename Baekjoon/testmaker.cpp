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

	ofile << h << " " << w << std::endl;
	for(int j = 0 ; j < w ; ++j) 
	{
		ofile << rand() % h + 1 << " " << rand() % h + 1 << " " << rand() % h + 1 << std::endl; 
	}
	int v1 = rand() % h + 1, v2 = rand() % h + 1;
	if(v1 == v2) v2 += 1;
	ofile << v1 << " " << v2 << std::endl;
	ofile.close();
	return 0;
}
