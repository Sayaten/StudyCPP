#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _Set
{
	char str[51];
	int len;
};
char (*pq)[51];
int main()
{
	int n, i;
	char str[51];
	
	scanf("%d", &n);
	
	pq = (char (*)[51])calloc(n, sizeof(char [51]));

	for(i = 0 ; i < n ; ++i)
	{
		
	}

	for(i = 0 ; i < n ; ++i)
	{
		strcpy(str, pq[i]);
		if(!strcmp(str, pq[i])) continue;
		printf("%s\n", str);
	}

	return 0;
}
