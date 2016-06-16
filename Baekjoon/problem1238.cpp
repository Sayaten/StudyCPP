#include <cstdio>
#include <algorithm>
#include <cstring>

int main()
{
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	int adj[n + 1][n + 1];

	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			adj[i][j] = (i == j) ? 0 : 1000000;

	while(m--)
	{
		int cost, i, j;
		scanf("%d %d %d", &i, &j, &cost);
		adj[i][j] = std::min(cost, adj[i][j]);
	}

	for(int k = 1 ; k <= n ; ++k)
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				if(adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];

	int mc = 0;
	for(int i = 1 ; i <= n ; ++i)
		mc = std::max(mc, adj[i][x] + adj[x][i]);

	printf("%d\n", mc);
	return 0;
}
