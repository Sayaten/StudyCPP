#include <stdio.h>
int main()
{
	int t, n[7], m, s, i;
	scanf("%d", &t);
	while(t--)
	{
		m = 0x7fffffff;
		s = 0;
		for(i = 0 ; i < 7 ; ++i)
		{
			scanf("%d", n + i);
			if(n[i] % 2 == 0)
			{
				s += n[i];
				m = m > n[i] ? n[i] : m;
			}
		}
		printf("%d %d\n", s, m);
	}
	return 0;
}
