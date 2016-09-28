#include <stdio.h>
#include <string.h>

int main()
{
	char s[101];
	int l, i;
	scanf("%s", s);
	l = strlen(s);
	for(i = 0 ; i < l / 2 ; ++i)
		if(s[i] != s[l - i - 1]) break;
	printf("%d\n", i == l/2);
	return 0;
}
