#include <cstdio>
#include <list>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>
int main()
{
	int cnt_V, cnt_E, s_V;
	scanf("%d %d\n%d", &cnt_V, &cnt_E, &s_V);
	std::list<std::pair<int, int> > adj[cnt_V + 1];
	while(cnt_E--)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(std::make_pair(w, v));
	}
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> > , std::greater< std::pair<int ,int> > > pq;
	pq.push(std::make_pair(0, s_V));
	int sp[cnt_V + 1];
	memset(sp, -1, sizeof(sp));
	while(!pq.empty())
	{
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if(sp[v] != -1) continue;
		for(auto iter : adj[v]) pq.push(std::make_pair(iter.first + w, iter.second));
		sp[v] = w;
	}
	for(int i = 1 ; i <= cnt_V ; ++i) 
		if(sp[i] == -1) printf("INF\n");
		else printf("%d\n", sp[i]);
	return 0;
}
