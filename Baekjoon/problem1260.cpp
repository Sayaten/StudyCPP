#include <cstdio>
#include <vector>
#include <list>
#include <cstring>
#include <algorithm>
int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	std::list<int> adj[n + 1];
	while(m--)
	{
		int i, j;
		bool already = false;
		scanf("%d %d", &i, &j);
		
		for(auto e : adj[i]) if(e == j) already = true;
		if(already) continue;

		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	for(auto &e :  adj) e.sort();

	bool visited[n + 1];
	std::list<int> bfs;
	std::vector<int> dfs;
	
	memset(visited, false, sizeof(visited));
	dfs.push_back(v);
	while(!dfs.empty())
	{
		int i = dfs.back();
		dfs.pop_back();
		if(visited[i]) continue;
		visited[i] = true;
		printf("%d ", i);
		for(auto iter = adj[i].rbegin() ; iter != adj[i].rend() ; ++iter) if(!visited[*iter]) dfs.push_back(*iter);
	}
	printf("\n");
	memset(visited, false, sizeof(visited));
	bfs.push_back(v);
	while(!bfs.empty())
	{
		int i = bfs.front();
		bfs.pop_front();
		if(visited[i]) continue;
		visited[i] = true;
		printf("%d ", i);
		for(auto e : adj[i]) if(!visited[e]) bfs.push_back(e);
	}
	printf("\n");
	return 0;
}
