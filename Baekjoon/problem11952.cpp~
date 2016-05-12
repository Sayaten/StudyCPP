#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <vector>
#include <functional>
 
using namespace std;
 
int main()
{
    int n, m, k, s;
    int p, q;
 
    scanf("%d %d %d %d\n%d %d", &n, &m, &k, &s, &p, &q);
 
    int deadCity[k + 1];
    for(int i = 0 ; i < k ; ++i) scanf("%d", deadCity + i);
 
    list<int> adj[n + 1];
 	long long cost[n + 1];
	for(int i = 1 ; i < n ; ++i) cost[i] = p;
    while(m--)
    {
        int i, j;
        scanf("%d %d", &i, &j);
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
     
    for(int i = 0 ; i < k ; ++i)
    {
        list< pair<int, int> > qu;
        qu.push_back(make_pair(0, deadCity[i]));
		cost[deadCity[i]] = (long long)0x7fffffffffffff;
        while(!qu.empty())
        {
            int v = qu.front().second;
            int w = qu.front().first;
            qu.pop_front();
            for(auto &e1 : adj[v]) 
            {
                if(w + 1 <= s && cost[e1] < q) 
				{
					cost[e1] = q;
					qu.push_back(make_pair(w + 1, e1));
				}
            }
        }
    }
	cost[n] = 0;
    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > pq;
    pq.push(make_pair(0, 1));
    long long sp[n + 1];
    memset(sp, -1, sizeof(sp));
    while(!pq.empty())
    {
        int v = pq.top().second;
        long long w = pq.top().first;
        pq.pop();
        if(sp[v] != -1) continue;
        sp[v] = w;
        for(auto e : adj[v]) pq.push(make_pair(w + cost[e], e));
    }
    printf("%lld\n", sp[n]);
    return 0;
}
