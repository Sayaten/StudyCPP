#include <cstdio>
#include <queue>
#include <cstring>

int main()
{
	int n, i, j, k;
	int nodes[100][100] = { 0, };
	int result[100][100] = { 0, };
	bool isVisited[100] = { false, };
	std::queue<int> path;

	scanf("%d", &n);

	for(i = 0 ; i < n ; ++i)
		for(j = 0 ; j < n ; ++j)
			scanf("%d", &(nodes[i][j]));

	for(i = 0 ; i < n ; ++i)
	{
		for(j = 0 ; j < n ; ++j)
		{
			memset(isVisited, false, sizeof(bool) * 100);
			path.push(i);
			isVisited[i] = true;
			while(true)
			{
				if(path.empty()) 
				{
					result[i][j] = 0;
					break;
				}
				else if(path.front() == j || result[path.front()][j] == 1)
				{
					result[i][j] = 1;
					while(path.empty()) path.pop();
					break;
				}
				else
				{
					for(k = 0 ; k < n ; ++k)
					{
						if(!isVisited[k] && nodes[path.front()][k] == 1)
						{
							result[i][k] = 1;
							path.push(k);
							isVisited[k] = true;
						}
					}
					path.pop();
				}
			}
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}
