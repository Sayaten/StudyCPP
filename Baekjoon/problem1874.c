#include <stdio.h>

int main()
{
	int s[100000], c[100000], n, num, i, st, pt, cp;
	char p[200000] = { 0, };
	scanf("%d", &n);
	st = pt = -1;
	cp = 0;

	for(i = 0 ; i < n ; ++i)
		scanf("%d", c + i);
	for(i = 1 ; i <= n ; ++i)
	{
		p[++pt] = '+';
		s[++st] = i;
		while(st != -1 && s[st] == c[cp])
		{
			p[++pt] = '-';
			--st;
			++cp;
		}
	}

	n *= 2;
	if(st != -1) printf("NO\n");
	else 
		for(i = 0 ; i < n ; ++i) printf("%c\n", p[i]);
	return 0;
}
