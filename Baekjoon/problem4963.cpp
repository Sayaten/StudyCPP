#include <cstdio>
#include <vector>
#include <cstring>

int main()
{
	while(true)
	{
		int w, h;
		scanf("%d %d", &w, &h);

		if(w == 0 && h == 0) break;

		char world[h + 1][w + 1];
		for(int i = 1 ; i <= h ; ++i)
			for(int j = 1 ; j <= w ; ++j)
				scanf("%d ", *(world + i) + j);
	
		int cnt = 0;
		std::vector< std::pair<int, int> > land;
		for(int i = 1 ; i <= h ; ++i)
			for(int j = 1 ; j <= w ; ++j)
			{
				if(world[i][j] == 1) 
				{
					land.push_back(std::make_pair(i, j));
					++cnt;
				}
				else continue;
				while(!land.empty())
				{
					int y = land.back().first;
					int x = land.back().second;
					land.pop_back();

					if(y - 1 >= 1 && x - 1 >= 1 && world[y - 1][x - 1] == 1) { land.push_back(std::make_pair(y - 1, x - 1)); world[y - 1][x - 1] = 2; }
					if(y - 1 >= 1 && x + 1 <= w && world[y - 1][x + 1] == 1) { land.push_back(std::make_pair(y - 1, x + 1)); world[y - 1][x + 1] = 2; }
					if(y + 1 <= h && x + 1 <= w && world[y + 1][x + 1] == 1) { land.push_back(std::make_pair(y + 1, x + 1)); world[y + 1][x + 1] = 2; } 
					if(y + 1 <= h && x - 1 >= 1 && world[y + 1][x - 1] == 1) { land.push_back(std::make_pair(y + 1, x - 1)); world[y + 1][x - 1] = 2; }
				
					if(y - 1 >= 1 && world[y - 1][x] == 1) { land.push_back(std::make_pair(y - 1, x)); world[y - 1][x] = 2; }
					if(y + 1 <= h && world[y + 1][x] == 1) { land.push_back(std::make_pair(y + 1, x)); world[y + 1][x] = 2; }
					if(x - 1 >= 1 && world[y][x - 1] == 1) { land.push_back(std::make_pair(y, x - 1)); world[y][x - 1] = 2; }
					if(x + 1 <= w && world[y][x + 1] == 1) { land.push_back(std::make_pair(y, x + 1)); world[y][x + 1] = 2; }
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}
