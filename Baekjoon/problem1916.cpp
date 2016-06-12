#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int n, m;
	scanf("%d\n%d", &n, &m);

	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

	vector< pair<int, int> > b[n + 1];

	while(m--)
	{
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		b[s].push_back( make_pair(c, e) );
	}

	int s, d;
	scanf("%d %d", &s, &d);

	int lc[n + 1];

	memset(lc, -1, sizeof(lc));
	
	for(auto e : b[s]) pq.push( make_pair(e.first, e.second) );
	lc[s] = 0;
	while(lc[d] == -1)
	{
		int c, v;
		c = pq.top().first;
		v = pq.top().second;
		pq.pop();
		if(lc[v] != -1) continue;

		lc[v] = c;
		for(auto e : b[v]) pq.push( make_pair(e.first + c, e.second) );
	}

	printf("%d\n", lc[d]);

	return 0;
}
