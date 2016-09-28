#include <stdio.h>
#include <stdlib.h>
int comp(const void *n1, const void *n2)
{
	return *(int *)n1 - *(int *)n2;
}
int main()
{
	int n, i;
	int *nums;
	scanf("%d", &n);
	nums = (int *)calloc(n, sizeof(int));
	for(i = 0 ; i < n ; ++i)
		scanf("%d", nums + i);
	qsort(nums, n, sizeof(int), comp);
	for(i = 0 ; i < n ; ++i)
		printf("%d\n", nums[i]);
	free(nums);
	return 0;
}
