#include <stdio.h>
#include <math.h>
int main()
{
	double rw, rh, dig, w, h;
	double r;
	scanf("%lf %lf %lf", &dig, &rh, &rw);
	r = dig / sqrt(rh * rh + rw * rw);
	w = r * rw;
	h = r * rh;
	printf("%d %d\n", (int)h, (int)w);
	return 0;
}
