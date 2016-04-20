#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <list>
#include <cstring>

int calcCost(const std::list< std::pair<int, int> > *adj, const int n, const int startV, const int endV);
int main()
{
	int n, e;

	scanf("%d %d", &n, &e);
	std::list< std::pair<int, int> > adj[n + 1];
	
	while(e--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(std::make_pair(c, b));
		adj[b].push_back(std::make_pair(c, a));
	}

	int mv1, mv2, total1 = 0, total2 = 0;
	bool cant1, cant2;
	scanf("%d %d", &mv1, &mv2);

	int cost;
	if((cost = calcCost(adj, n, 1, mv1)) == -1) { cant1 = true; }
	else total1 += cost;
	if((cost = calcCost(adj, n, mv1, mv2)) == -1) { cant1 = true; }
	else total1 += cost;
	if((cost = calcCost(adj, n, mv2, n)) == -1) { cant1 = true; }
	else total1 += cost;

	if((cost = calcCost(adj, n, 1, mv2)) == -1) { cant2 = true; }
	else total2 += cost;
	if((cost = calcCost(adj, n, mv2, mv1)) == -1) { cant2 = true; }
	else total2 += cost;
	if((cost = calcCost(adj, n, mv1, n)) == -1) { cant2 = true; }
	else total2 += cost;

	if(cant1 && cant2) printf("-1\n");
	else printf("%d\n", std::min(cant1?0x7fffffff:total1, cant2?0x7fffffff:total2));
	return 0;
}

int calcCost(const std::list< std::pair<int, int> > *adj, const int n, const int startV, const int endV)
{
	int sp[n + 1];
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;
	memset(sp, -1, sizeof(sp));	
	pq.push(std::make_pair(0, startV));
	while(!pq.empty())
	{
		int v = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if(sp[v] != -1) continue;
		for(auto e : adj[v]) pq.push(std::make_pair(e.first + w, e.second));
		sp[v] = w;
	}
	if(sp[endV] == -1) return -1;
	else return sp[endV];
}
