#include <cstdio>
#include <cstring>
#include <algorithm>
int main()
{
	int n, m;
	scanf("%d\n%d", &n, &m);

	int adj[n + 1][n + 1];
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n; ++j) adj[i][j] = (i == j) ? 0 : 200000;
	while(m--)
	{
		int i, j, w;
		scanf("%d %d %d", &i, &j, &w);
		adj[i][j] = std::min(adj[i][j], w);
	}
	for(int k = 1 ; k <= n ; ++k)
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1; j <= n ; ++j)
				if(adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];

	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n; ++j) printf("%d ", adj[i][j] >= 200000 ? 0 : adj[i][j]);
		printf("\n");
	}
	return 0;
}
