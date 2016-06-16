#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	priority_queue< unsigned, vector< unsigned >, less< unsigned > > pq;
	
	while(n--)
	{
		unsigned x;
		scanf("%d", &x);
		if(!x)
		{
			printf("%d\n", pq.empty() ? 0 : pq.top());
			if(!pq.empty()) pq.pop();
		}
		else pq.push(x);
	}
	return 0;
}
