#include <stdio.h>
int main()
{
	int n, c, i;
	int s[1000];
	unsigned long long t;
	
	scanf("%d", &n);
	for(i = 0 ; i < n ; ++i)
		scanf("%d", s + i);
	scanf("%d", &c);

	t = 0;

	for(i = 0 ; i < n ; ++i)
		t += s[i] % c ? s[i] / c + 1 : s[i] / c; 
	
	printf("%llu\n", t * c);

	return 0;
}
