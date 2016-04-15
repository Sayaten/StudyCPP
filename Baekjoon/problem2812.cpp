#include <cstdio>
#include <vector>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	std::vector<char> v;

	char num[n + 1];
	scanf("%s", num);

	int pos = 0;
	while(n--)
	{
		while(!v.empty() && v.back() < num[pos] && k > 0) 
		{
			v.pop_back();
			--k;
		}
		v.push_back(num[pos++]);
	}
	while(k--) v.pop_back();
	for(auto e : v) printf("%c", e);
	printf("\n");
	return 0;
}
