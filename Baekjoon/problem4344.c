#include <stdio.h>
int main()
{
	int c, n, i, a, o;
	int s[1000];
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d", &n);
		a = 0;
		for(i = 0; i < n ; ++i)
		{
			scanf("%d", s + i);
			a += s[i];
		}
		a /= n;
		o = 0;
		for(i = 0; i < n ; ++i)
			if(s[i] > a) ++o;
		printf("%.3lf%%\n", (double)o / n * 100);
	}
	return 0;
}
