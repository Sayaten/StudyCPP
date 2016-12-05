#include <stdio.h>
#include <string.h>
int main()
{
	char input[100001], b;
	int s[50001] = { 0 };
	int t = -1, l, i, cnt;
	scanf("%s", input);
	l = strlen(input); 

	for(i = 0 ; i < l ; ++i)
	{
		if(input[i] == '(')
		{
			s[t + 1] = t == -1 ? 0 : s[t] + 1;
			b = '(';
			++t;
		}
		else
		{
			if(b == '(') cnt += s[t--];
			else
			{
				--t;
				++cnt;
			}
			b = ')';
		}
	}
	printf("%d\n", cnt);
	return 0;
}
