#include <stdio.h>
#include <string.h>
int main()
{
	int la, lb, i;
	char a[10002] = { 0, }, b[10002] = { 0, };
	long long r, sa, sb;

	scanf("%s %s", a, b);

	la = strlen(a);
	lb = strlen(b);

	sa = sb = 0;
	for(i = 0 ; i < la ; ++i)
		sa += (a[i] - '0');
	for(i = 0 ; i < lb ; ++i)
		sb += (b[i] - '0');
	r = sa * sb;
	printf("%lld\n", r);

	return 0;
}
