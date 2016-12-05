#include <cstdio>

int main()
{
	bool ary[2001] = { 0, };
	int n;

	scanf("%d", &n);
	while(n--)
	{
		int tmp;
		scanf("%d", &tmp);
		ary[tmp + 1000] = true;
	}

	for(int i = 0 ; i < 2001 ; ++i)
		if(ary[i]) printf("%d ", i - 1000);
	return 0;
}
