#include <stdio.h>
int main()
{
	int i, cnt, n;
	cnt = 0;
	scanf("%d", &n);
	for(i = 64 ; i >= 1 ; i /= 2)
	{
		if(n / i) 
		{
			++cnt;
			n %= i;
            if(!n) break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
