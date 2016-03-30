#include <cstdio>

int main()
{
	int n, x, input;
	scanf("%d %d", &n, &x);

	for(int i = 0 ; i < n ; ++i)
	{
		scanf("%d", &input);
		if(input < x) printf("%d ", input); 
	}
	printf("\n");
	return 0;
}
