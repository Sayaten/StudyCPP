#include <cstdio>
#include <algorithm>

int main()
{
	int n;
	long long  m;
	scanf("%d %lld", &n, &m);

	long long tree[n];
	long long max = 0, min = 0;

	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%lld", tree + i);
		max = std::max(max, tree[i]);
	}

	min = 0;

	while(min <= max)
	{
		long long total = 0;
		long long middle = (max + min) / 2;
		for(int i = 0 ; i < n ; ++i) 
			total += std::max(tree[i] - middle, 0ll);
		if(total > m) min = middle + 1;
		else if(total < m) max = middle - 1;
		else { min = middle; break; }
	}

	printf("%lld\n", std::min(min, max));
	return 0;
}
