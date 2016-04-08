#include <cstdio>
#include <queue>
#include <cstring>

struct Node
{
	Node(const int &row, const int &col, const int &count) : row(row), col(col), count(count) { }
	void setData(const int& row, const int& col, const int& count)
	{
		this -> row = row;
		this -> col = col;
		this -> count = count;
	}
	int row;
	int col;
	int count;
};

void copy_path(std::queue<Node> &destiny, std::queue<Node> &origin);
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int map[n][m];
	int saved_map[n][m];
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			scanf("%1d", &map[i][j]);

	std::queue<Node> path;
	std::queue<Node> saved_path;
	Node broken_wall(0, 0, 0);

	bool isBroken = false, isRestored = false;
	int row, col, count, min_count = 0x7fffffff;
	path.push(Node(0, 0, 1));
	while(true)
	{
		if(path.empty())
		{
			if(isBroken)
			{
				memcpy(map, saved_map, sizeof(map));
				copy_path(path, saved_path);
				map[broken_wall.row][broken_wall.col] = 3;
				isBroken = false;
			}
			else break;
		}
		row = path.front().row;
		col = path.front().col;
		count = path.front().count;
		printf("%d %d %d %d\n", row, col, map[row][col], count);
		path.pop();
		if(map[row][col] == 1)
		{
			if(isBroken) continue;
			else
			{
				memcpy(saved_map, map, sizeof(map));
				copy_path(saved_path, path);
				broken_wall.setData(row, col, count);
				map[row][col] = 0;
				isBroken = true;
			}
		}
		if(map[row][col] == 3) continue;
		if(row == n - 1 && col == m - 1) 
		{
			min_count = std::min(count, min_count);
			break;
		}
		map[row][col] = 2;
		if(row - 1 >= 0 && map[row - 1][col] <= 1) path.push(Node(row - 1, col, count + 1));
		if(row + 1 < n  && map[row + 1][col] <= 1) path.push(Node(row + 1, col, count + 1));
		if(col - 1 >= 0 && map[row][col - 1] <= 1) path.push(Node(row, col - 1, count + 1));
		if(col + 1 < m  && map[row][col + 1] <= 1) path.push(Node(row, col + 1, count + 1));
	}
	if(min_count == 0x7fffffff) min_count = -1;
	printf("%d\n", min_count);
	return 0;
}

void copy_path(std::queue<Node> &destination, std::queue<Node> &origin)
{
	while(!destination.empty()) destination.pop();
	for(int i = 0 ; i < origin.size() ; ++i)
	{
		destination.push(origin.front());
		origin.push(origin.front());
		origin.pop();
	}
}
