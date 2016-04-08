#include <cstdio>
#include <queue>
#include <cstring>

struct Node
{
	Node(const int &row, const int &col, const int &count) : row(row), col(col), count(count) { }
	Node() = default;
	void setData(const int &row, const int &col, const int &count)
	{
		this -> row = row;
		this -> col = col;
		this -> count = count;
	}
	int row;
	int col;
	int count;
};

int main()
{
	int n, m, min_count = 0x7fffffff;
	scanf("%d %d", &n, &m);

	int map[n][m];
	int backup_map[n][m];
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			scanf("%1d", &map[i][j]);
	int broken_count_before = 0;
	int broken_count_now = -1;
	memcpy(backup_map, map, sizeof(backup_map));
	while(broken_count_before != broken_count_now)
	{
		int row, col, count;
		bool isBroken = false;	
		std::queue<Node> path;
		path.push(Node(0, 0, 1));
		Node broken_wall;
		broken_count_before = broken_count_now;
		while(true)
		{
			if(path.empty()) break;
			row = path.front().row;
			col = path.front().col;
			count = path.front().count;
			path.pop();
			if(map[row][col] == 1)
				if(isBroken) continue;
				else
				{
					isBroken = true;
					broken_wall.setData(row, col, count);
					++broken_count_now;
				}
			else if(map[row][col] == 3) continue;
			if(row == n - 1 && col == m - 1) 
			{
				min_count = std::min(min_count, count);
				break;
			}
			if(row - 1 >= 0 && map[row - 1][col] <= 1) path.push(Node(row - 1, col, count + 1));
			if(row + 1 < n  && map[row + 1][col] <= 1) path.push(Node(row + 1, col, count + 1));
			if(col - 1 >= 0 && map[row][col - 1] <= 1) path.push(Node(row, col - 1, count + 1));
			if(col + 1 < m	&& map[row][col + 1] <= 1) path.push(Node(row, col + 1, count + 1));
			map[row][col] = 2;
		}
		if(isBroken) 
		{
			backup_map[broken_wall.row][broken_wall.col] = 3;
			memcpy(map, backup_map, sizeof(map));
		}
	}
	printf("%d\n", min_count == 0x7fffffff ? -1 : min_count);
	return 0;
}
