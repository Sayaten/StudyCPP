#include <cstdio>
#include <queue>
#include <cstring>
#include <list>

struct Node
{
	Node(const int &row, const int &col) : row(row), col(col) { }
	int row;
	int col;
};

struct Door : public Node
{
	Door(const int &row, const int &col, const char &doorChar) : Node(row, col), doorChar(doorChar) { }
	char doorChar;
};

int main()
{
	int total_case, now_case;
	int h, w, row, col, type, cnt;
	int i, j, len;
	char map[100][101], input_keys[27];
	bool keys[26], cantGo[100][100];
	std::queue<Node> path;
	std::list<Door> locked_doors;

	scanf("%d", &total_case);
	while(total_case--)
	{
		scanf("%d %d", &h, &w);
		for(i = 0 ; i < h ; ++i)
			scanf("%s", map[i]);
		memset(keys, false, sizeof(bool) * 26);
		memset(cantGo, false, sizeof(bool) * 10000);
		cnt = 0;
		scanf("%s", input_keys);
		if(input_keys[0] != '0')
		{
			len = strlen(input_keys);
			for(i = 0 ; i < len ; ++i) 
				keys[input_keys[i] - 'a'] = true;
		}	
		for(i = 0 ; i < h ; ++i)
			for(j = 0 ; j < w ; ++j)
			{
				if(map[i][j] == '*')
					cantGo[i][j] = true;
				if(i == 0 || i == h - 1 || j == 0 || j == w - 1)
				{
					if(map[i][j] != '*')
						path.push(Node(i, j));
					cantGo[i][j] = true;
				}
			}

		while(!path.empty())
		{
			row = path.front().row;
			col = path.front().col;
			type = map[row][col];
			printf("%d %d %d\n", row, col, type);
			if(type == '$') ++cnt;
			else if('A' <= type && type <= 'Z' &&!keys[type - 'A'])
			{
				locked_doors.push_back(Door(row, col, type));
				path.pop();
				continue;
			}
			else if('a' <= type && type <= 'z')
			{	
				keys[type - 'a'] = true;
				auto iter = locked_doors.begin();

				while(iter != locked_doors.end())
				{
					if((iter -> doorChar + 32) == type) 
					{
						path.push(Node(iter -> row, iter -> col));
						iter = locked_doors.erase(iter);
					}
					else ++iter;
				}
			}
			if(row - 1 >= 0 && !cantGo[row - 1][col]) 
			{
				path.push(Node(row - 1, col));
				cantGo[row - 1][col] = true;
			}
			if(row + 1 < h && !cantGo[row + 1][col]) 
			{
				path.push(Node(row + 1, col));
				cantGo[row + 1][col] = true;
			}
			if(col - 1 >= 0 && !cantGo[row][col - 1]) 
			{
				path.push(Node(row, col - 1));
				cantGo[row][col - 1] = true;
			}
			if(col + 1 < w && !cantGo[row][col + 1]) 
			{
				path.push(Node(row, col + 1));
				cantGo[row][col + 1] = true;
			}
			path.pop();
		}
		printf("%d\n", cnt);
	}
	return 0;
}
