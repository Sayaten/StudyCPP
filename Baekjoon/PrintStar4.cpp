#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++i)
	{
		printf("%*c", i, '*');
		for(int j = n - i; j > 0 ; --j)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
