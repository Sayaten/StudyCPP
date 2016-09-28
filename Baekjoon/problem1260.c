#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
	bool v[1001] = { 0, }, e[1001][1001] = { 0, };
	int n, m, sv, v1, v2, i, no;
	int s[1001] = { 0, }, t;
	int q[1001] = { 0, }, f, r;

	scanf("%d %d %d", &n, &m, &sv);
	while(m--)
	{
		scanf("%d %d", &v1, &v2);
		e[v1][v2] = 1;
		e[v2][v1] = 1;
	}

	s[t = 0] = sv;
	while(t != -1)
	{
		no = s[t--];
		if(v[no]) continue;
		v[no] = 1;
		printf("%d ", no);
		for(i = n; i => 1 ; --i)
			if(e[no][i] && !v[i]) s[++t] = i;
	}
	printf("\n");

	memset(v, 0, sizeof(v));
	q[f = 0] = sv; 
	r = 1;
	while(f != r)
	{
		no = q[f++];
		if(v[no]) continue;
		v[no] = 1;
		printf("%d ", no);
		for(i = 1 ; i <= n ; ++i)
			if(e[no][i] && !v[i]) q[r++] = i;
	}
	
	return 0;
}
