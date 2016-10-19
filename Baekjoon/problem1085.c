#include <stdio.h>
int min(int n1, int n2)
{
	return n1 < n2 ? n1 : n2;
}
int main()
{
	int x, y, w, h, dx, dy;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	dx = w - x;
	dy = h - y;
	printf("%d\n", min(min(x, dx), min(y, dy)));
	return 0;
}
