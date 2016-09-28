#include <stdio.h>
#include <string.h>

int main()
{
	char s[51];
	int n, t, l, i;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", s);
		l = strlen(s);
		t = 0;		
		for(i = 0 ; i < l ; ++i)
		{
			if(s[i] == '(') ++t;
			else --t;
			if(t < 0) break;
		}
		if(t == 0) printf("YES\n");
		else printf("NO\n");

	}
	return 0;
}
