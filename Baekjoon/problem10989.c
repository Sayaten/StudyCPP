#include <stdio.h>
int main()
{
	int ary[10001] = { 0, }, n, input, i, j;
	scanf("%d", &n);

	for(i = 0 ; i < n ; ++i)
	{
		scanf("%d", &input);
		++ary[input];
	}
	for(i = 0 ; i < 10001 ; ++i)
	{
		if(ary[i])
		{
			for(j = 0 ; j < ary[i] ; ++j)
				printf("%d\n", i);
		}
	}
	return 0;
}
