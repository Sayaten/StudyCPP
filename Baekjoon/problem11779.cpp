#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>
#include <list>

using namespace std;

int main()
{
	int n, m;
	scanf("%d\n%d", &n, &m);

	priority_queue< pair< int, pair<int, int> >, vector< pair< int, pair<int, int> > >, greater< pair< int, pair<int, int> > > > pq;

	vector< pair<int, int> > b[n + 1];

	while(m--)
	{
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		b[s].push_back( make_pair(c, e) );
	}

	int s, d, now;
	scanf("%d %d", &s, &d);

	int lc[n + 1];
	int from[n + 1];

	memset(lc, -1, sizeof(lc));
	
	for(auto e : b[s]) pq.push( make_pair(e.first, make_pair(s, e.second) ) );
	lc[s] = 0;

	while(lc[d] == -1)
	{
		int c, v1, v2;
		c = pq.top().first;
		v1 = pq.top().second.first;
		v2 = pq.top().second.second;
		pq.pop();
		if(lc[v2] != -1) continue;

		lc[v2] = c;
		from[v2] = v1;
		for(auto e : b[v2]) pq.push( make_pair(e.first + c, make_pair(v2, e.second) ) );
	}

	list< int > p;
	int v = from[d];
	while(v != s)
	{
		p.push_front(v);
		v = from[v];
	}
	printf("%d\n", lc[d]);
	printf("%lu\n", p.size() + 2);
	printf("%d ", s);
	for(auto iter = p.begin() ; iter != p.end() ; ++iter)
		printf("%d ", *iter);
	printf("%d\n", d);
	return 0;
}
