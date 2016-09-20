#include <stdio.h>
#include <string.h>
int main()
{
	char str[5][62] = { '\0', }, input[16], c;
	int len, i, j, n;

	scanf("%s", input);
	len = strlen(input);

	for(i = 0 ; i < 5 ; ++i)
		for(j = 0 ; j < len * 4 + 1 ; ++j)
			str[i][j] = '.';

	str[2][0] = '#';
	for(i = 0 ; i < len ; ++i)
	{
		if(i % 3 == 2) c = '*';
		else c = '#';

		str[0][2 + i * 4] = 
		str[1][1 + i * 4] = str[1][3 + i * 4] =
		str[2][4 + i * 4] = 
		str[3][1 + i * 4] = str[3][3 + i * 4] =
		str[4][2 + i * 4] = c;

		if(i % 3 == 2) str[2][i * 4] = c;
		str[2][2 + i * 4] = input[i];
	}

	for(i = 0 ; i < 5 ; ++i)
		printf("%s\n", str[i]);

	return 0;
}
