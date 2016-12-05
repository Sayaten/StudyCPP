#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char str1[1001], str2[1001];
	int cnt1[26] = { 0, }, cnt2[26] = { 0, };
	int l1, l2, i, t;

	scanf("%s\n%s", str1, str2);
	l1 = strlen(str1);
	l2 = strlen(str2);

	for(i = 0 ; i < l1 ; ++i)
		++cnt1[str1[i] - 'a'];

	for(i = 0 ; i < l2 ; ++i)
		++cnt2[str2[i] - 'a'];

	t = 0;

	for(i = 0 ; i < 26 ; ++i)
		t += abs(cnt1[i] - cnt2[i]);

	printf("%d\n", t);

	return 0;
}
