#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; ++i)
	{
		printf("%*c", n - i, '*');
		for(int j = i; j > 0 ; --j)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
