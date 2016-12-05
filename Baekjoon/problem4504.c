#include <stdio.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	while(1)
	{
		scanf("%d", &i);
		if(!i) break;
		printf("%d is%sa multiple of %d.\n", i, i % n ? " NOT " : " ", n);
	}
	return 0;
}
