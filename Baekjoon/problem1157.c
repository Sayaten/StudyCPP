#include <stdio.h>
#include <string.h>
int main()
{
	int c[26] = { 0, }, l, i, f, s, fv, sv;
	char str[1000000];

	scanf("%s", str);
	l = strlen(str);

	for(i = 0 ; i < l ; ++i)
		if(str[i] >= 'a') ++c[str[i] - 'a'];
		else ++c[str[i] - 'A'];

	f = s = fv = sv = -1;
	
	for(i = 0 ; i < 26 ; ++i)
	{
		if(c[i] >= fv)
		{
			s = f;
			f = i;
			sv = fv;
			fv = c[i];
		}
	}

	if(sv == fv) printf("?\n");
	else printf("%c\n", 'A' + f);

	return 0;
}
