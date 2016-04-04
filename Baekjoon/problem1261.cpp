#include <cstdio>
#include <queue>

struct Node
{
	Node(const int &row, const int &col, const int &count) : row(row), col(col), count(count) { }
	int row;
	int col;
	int count;
};

int main()
{
	int n, m;
	std::queue<Node> path;
	std::queue<Node> walls;
	scanf("%d %d", &m, &n);

	int map[100][100];
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			scanf("%1d", &map[i][j]);

	bool isVisited[100][100] = { false, };
	int row, col, count;
	path.push(Node(0, 0, 0));
	while(true)
	{
		if(path.empty()) 
		{
			row = walls.front().row;
			col = walls.front().col;
			count = walls.front().count;
			map[row][col] = 0;
			walls.pop();
		}
		else
		{
			row = path.front().row;
			col = path.front().col;
			count = path.front().count;
			path.pop();
		}
		if(isVisited[row][col]) continue;
		if(row == n - 1 && col == m - 1) break;
		if(map[row][col]) 
		{
			walls.push(Node(row, col, count + 1));
			continue;
		}
		isVisited[row][col] = true;
		if(row - 1 >= 0 && !isVisited[row - 1][col]) path.push(Node(row - 1, col, count));
		if(row + 1 < n  && !isVisited[row + 1][col]) path.push(Node(row + 1, col, count));
		if(col - 1 >= 0 && !isVisited[row][col - 1]) path.push(Node(row, col - 1, count));
		if(col + 1 < m  && !isVisited[row][col + 1]) path.push(Node(row, col + 1, count));
	}
	printf("%d\n", count);
	return 0;
}
