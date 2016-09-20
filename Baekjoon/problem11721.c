#include <stdio.h>
#include <string.h>
int main()
{
	char str[101], temp[11];
	int len, cnt, i;
	scanf("%s", str);
	len = strlen(str);
	cnt = len / 10 + 1;
	for(i = 0 ; i < cnt ; ++i)
	{
		strncpy(temp, str + i*10, 10);
		printf("%s\n", temp);
	}
	return 0;
}
