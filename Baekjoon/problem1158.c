#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m, p, i, j;
	int *c;

	scanf("%d %d", &n, &m);
	c = (void *)calloc(n, sizeof(int));
	p = 0;
	
	printf("<");
	for(i = 0 ; i < n ; ++i)
	{
		for(j = 0 ; j < m ; ++j)
		{
			p = (p + 1) % n;
			if(c[p]) --j;
		}
		printf("%d", p ? p : n);
		c[p] = 1;
		if(i != n - 1) printf(", ");
	}
	printf(">");
	return 0;
}
