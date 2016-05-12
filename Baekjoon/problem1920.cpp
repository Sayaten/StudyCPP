#include<cstdio>
#include<set>

int main()
{
	int n;
	scanf("%d", &n);

	std::set<int> s;
	for(int i = 0 ; i < n ; ++i)
	{
		int a;
		scanf("%d", &a);
		s.insert(a);
	}

	int m;
	scanf("%d", &m);

	while(m--)
	{
		int num;
		scanf("%d", &num);
		printf("%d\n", s.find(num) != s.end());
	}
	return 0;
}
