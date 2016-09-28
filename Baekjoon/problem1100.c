#include <stdio.h>
int main()
{
	char b[8][9];
	int i, j, c;
	for(i = 0 ; i < 8 ; ++i)
		scanf("%s", *(b + i));

	c = 0;
	for(i = 0 ; i < 8 ; ++i)
		for(j = i % 2 ; j < 8 ; j += 2)
			if(b[i][j] == 'F') ++c;
	
	printf("%d\n", c);
	return 0;
}
