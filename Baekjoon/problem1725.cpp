#include <cstdio>
#include <stack>

int main()
{
	int n, pos = 1, height, max = -1;
	std::stack< std::pair<int, int> > area;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &height);
		if(area.empty() || area.top().second < height) area.push(std::make_pair(pos, height));
		else 
		{
			while(!area.empty() && area.top().second >= height) 
			{	
				std::pair<int, int> t(area.top());
				area.pop();
				if(area.empty()) max = std::max((pos - 1) * t.second, max);
				else max = std::max((pos - 1 - area.top().first) * t.second, max);
			}
			area.push(std::make_pair(pos, height));
		}
		++pos;
	}
	while(!area.empty()) 
	{
		std::pair<int, int> t(area.top());
		area.pop();
		if(area.empty()) max = std::max(t.first * t.second, max);
		else max = std::max((t.first - area.top().first) * t.second, max);
	}	
	printf("%d\n", max);
	return 0;
}


