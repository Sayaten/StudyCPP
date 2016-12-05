#include <stdio.h>

int main()
{
	int loop = 3, n, t;
	long long s[100000];
	long long input;

	while(loop--)
	{
		t = -1;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%lld", &input);

			if(input == 0) continue;
			else if(t == -1) s[++t] = input;
			else
			{
				while(t >= 0 && ((input ^ s[t]) < 0)) input += s[t--];
				if(input) s[++t] = input;
			}
		}
		if(t == -1) printf("0\n");
		else if(s[t] > 0) printf("+\n");
		else printf("-\n");
	}	

	return 0;
}

