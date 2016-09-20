#include <stdio.h>

int main()
{
	int num[20], t, input, i, j, k, div, temp;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &input);
		for(i = 2 ; i <= 64 ; ++i)
		{
			div = i;
			num[0] = input % div;
			temp = input - num[0];
			for(j = 1 ; j < 20 ; ++j)
			{
				if(temp <= 0) break;
				div *= i;
				num[j] = temp % div;
				temp -= num[j];
				num[j] /= div / i;
			}
			temp = 1;
			--j;
			for(k = 0 ; k <= j / 2; ++k)
			{
				if(num[k] != num[j - k])
				{
					temp = 0;
					break;
				}
			}
			if(temp == 1)
			{
				printf("1\n");
				break;
			}
			else if(i == 64)
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
