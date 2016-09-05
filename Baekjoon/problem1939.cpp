#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int adj[n + 1][n + 1];
	memset(adj, 0xff, sizeof(adj));

	while(m--)
	{
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		adj[v1][v2] = max(adj[v1][v2], cost);
	}
	return 0;
}
