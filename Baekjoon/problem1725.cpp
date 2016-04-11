#include <cstdio>
#include <stack>

int main()
{
	int n, pos = 1, height;
	stack< std::pair<int, int> > area;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &height);
		if(area.empty()) area.push(pos, height);
		else 
		{
			int part_area = (pos - area.top().first) * area.top().height;
			if(height > area.top().height) part_area += area.top().height;

			if(part_area >
			
		}

	}
	return 0;
}
