#include <cstdio>
#include <queue>

struct Node
{
	Node(const int &row, const int &col, const int &value) : row(row), col(col), value(value) { }
	int row;
	int col;
	int value;
};

int main()
{
	int n, m;
	std::queue<Node> path;
	scanf("%d %d", &n, &m);
	int maze[n][m];
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			scanf("%1d", &(maze[i][j]));
	path.push(Node(0, 0, 1));
	maze[0][0] = 0;
	while(true)
	{
		if(path.front().row == n - 1 && path.front().col == m - 1) break;
		else
		{
			if(path.front().col + 1 < m && maze[path.front().row][path.front().col + 1] == 1)
			{
				path.push(Node(path.front().row, path.front().col + 1, path.front().value + 1));
				maze[path.front().row][path.front().col + 1] = 0;
			}
			if(0 <= path.front().col - 1 && maze[path.front().row][path.front().col - 1] == 1)
			{
				path.push(Node(path.front().row, path.front().col - 1, path.front().value + 1));
				maze[path.front().row][path.front().col - 1] = 0;
			}
			if(path.front().row + 1 < n && maze[path.front().row + 1][path.front().col] == 1)
			{
				path.push(Node(path.front().row + 1, path.front().col, path.front().value + 1));
				maze[path.front().row + 1][path.front().col] = 0;
			}
			if(0 <= path.front().row - 1 && maze[path.front().row - 1][path.front().col] == 1)
			{
				path.push(Node(path.front().row - 1, path.front().col, path.front().value + 1));
				maze[path.front().row - 1][path.front().col] = 0;
			}
			path.pop();
		}
	}
	printf("%d\n", path.front().value);
	return 0;
}
