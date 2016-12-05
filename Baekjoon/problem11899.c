#include <stdio.h>
#include <string.h>
int main()
{
	char in[51], st[51];
	int t, l, i;
	t = -1;
	scanf("%s", in);
	l = strlen(in);
	for(i = 0 ; i < l ; ++i)
	{
		if(in[i] == '(') st[++t] = '(';
		else if(in[i] == ')')
		{
			if(t >= 0 && st[t] == '(') st[t--] = 0;
			else st[++t] = ')';
		}
	}
	printf("%d\n", t + 1);
	return 0;
}
