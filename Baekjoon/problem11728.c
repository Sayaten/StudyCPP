#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m, num, i, j, k;
	int *ary1, *ary2;

	scanf("%d %d", &n, &m);

	ary1 = (int *)calloc(n, sizeof(int));
	ary2 = (int *)calloc(m, sizeof(int));

	for(i = 0 ; i < n ; ++i)
	{
		scanf("%d", &num);
		ary1[i] = num;
	}
	for(i = 0 ; i < m ; ++i)
	{
		scanf("%d", &num);
		ary2[i] = num;
	}

	i = j = 0;
	while(i < n && j < m)
	{
		if(ary1[i] < ary2[j]) printf("%d ", ary1[i++]);
		else printf("%d ", ary2[j++]);
	}
	for(; i < n ; ++i) printf("%d ", ary1[i]);
	for(; j < m ; ++j) printf("%d ", ary2[j]);
	
	free(ary1);
	free(ary2);

	return 0;
}
