#include <cstdio>
#include <list>
#include <algorithm>

struct Node
{
	Node(const int row, const int col, const int day) : row(row), col(col), day(day) { }
	int row;
	int col;
	int day;
};

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	char box[n][m];

	std::list<Node> l;
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0; j < m ; ++j)
		{
			scanf("%d", *(box + i) + j);
			if(box[i][j] == 1) l.push_back(Node(i, j, 0));
		}

	int total = 0;
	while(!l.empty())
	{
		int row, col, day;
		row = l.front().row;
		col = l.front().col;
		day = l.front().day;
		l.pop_front();
		total = std::max(total, day);
		if(row - 1 >= 0 && box[row - 1][col] == 0) { l.push_back(Node(row - 1, col, day + 1)); box[row - 1][col] = 1; }
		if(row + 1 <  n && box[row + 1][col] == 0) { l.push_back(Node(row + 1, col, day + 1)); box[row + 1][col] = 1; }
		if(col - 1 >= 0 && box[row][col - 1] == 0) { l.push_back(Node(row, col - 1, day + 1)); box[row][col - 1] = 1; }
		if(col + 1 <  m && box[row][col + 1] == 0) { l.push_back(Node(row, col + 1, day + 1)); box[row][col + 1] = 1; }
	}
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0; j < m ; ++j)
			if(!box[i][j])
			{
				printf("-1\n");
				return 0;
			}
	printf("%d\n", total);
	return 0;
}


