#include <stdio.h>
#include <stdlib.h>
int comp(const void *n1, const void*n2)
{
	return (*((int *)n1) - *((int *)n2));
}
int main()
{
	int t, n[10], i;
	scanf("%d", &t);
	while(t--)
	{
		for(i = 0 ; i < 10 ; ++i)
			scanf("%d", n + i);
		qsort(n, 10, sizeof(int), comp);
		printf("%d\n", n[7]);
	}
	return 0;
}
