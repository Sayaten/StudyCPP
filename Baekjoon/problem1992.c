#include <stdio.h>
#include <string.h>

char board[65][65];

void qt(int startx, int starty, int size, char *res);
int main()
{
	int n, i;
	char res[10000] = { 0, };
	scanf("%d", &n);

	for(i = 0 ; i < n ; ++i)
		scanf("%s", *(board + i));

	qt(0, 0, n, res);
	printf("%s\n", res);

	return 0;
}

void qt(int startx, int starty, int size, char *res)
{
	char lt[2500] = { 0, }, rt[2500] = { 0, }, lb[2500] = { 0, }, rb[2500] = { 0, };
	if(size == 1) res[0] = board[starty][startx];
	else
	{
		qt(startx, starty, size / 2, lt);
		qt(startx + size / 2, starty, size / 2, rt);
		qt(startx, starty + size / 2, size / 2, lb);
		qt(startx + size / 2, starty + size / 2, size / 2, rb);
		
		if( (strlen(lt) + strlen(rt) + strlen(lb) + strlen(rb) == 4) && 
			!(strcmp(lt, rt) || strcmp(rt, lb) || strcmp(lb, rb)) )
			strcat(res, lt);
		else
		{
			strcat(res, "(");
			strcat(res, lt);
			strcat(res, rt);
			strcat(res, lb);
			strcat(res, rb);
			strcat(res, ")");
		}
	}
}
