#include <cstdio>
#include <array>
#include <functional>

using namespace std;

int main()
{
	array < pair< pair< pair<int, int>, pair<int, int> >, bool>, 1000000 > paper;
	int width, height, n, last = 0;

	scanf("%d %d\n%d", &width, &height, &n);
	
	paper[0] = make_pair(make_pair(make_pair(0, 0), make_pair(width, height)), true);
	
	while(n--)
	{
		int x, y, lchild;
		bool isWhite = true;
		scanf("%d %d", &x, &y);
		lchild = 1;
		while(paper[lchild].first.second.second != 0)
		{
			if(isWhite) 
			{
				if(paper[lchild].first.first.second <= y && y <= paper[lchild].first.second.second)
					lchild = lchild * 2 + 1;
				else
					lchild = (lchild + 1) * 2 + 1;
			}
			else
			{
				if(paper[lchild].first.first.first <= x && x <= paper[lchild].first.second.first)
					lchild = lchild * 2 + 1;
				else
					lchild = (lchild + 1) * 2 + 1;
			}

			isWhite = !isWhite;
		}

		int node = (lchild - 1) / 2;
		if(isWhite)
		{
			paper[lchild] = make_pair(make_pair(
						make_pair(paper[node].first.first.first, paper[node].first.first.second), 
						make_pair(paper[node].first.second.first, y)), true);
			paper[lchild + 1] = make_pair(make_pair(
											make_pair( paper[node].first.first.first, y),
											make_pair( paper[node].first.second.first, paper[node].first.second.second)), true);
		}
		else
		{
			paper[lchild] = make_pair(make_pair(
						make_pair(paper[node].first.first.first, paper[node].first.first.second), 
						make_pair(x, paper[node].first.second.second)), true);
			paper[lchild + 1] = make_pair(make_pair(
						make_pair( x, paper[node].first.first.second),
						make_pair( paper[node].first.second.first, paper[node].first.second.second)), true);
		}
		paper[node].second = false;
		last = max(last, lchild + 1);
	}
	
	int minArea = 1600000000, maxArea = 0;

	for(int i = 0 ; i <= last ; ++i)
	{
		if(paper[i].first.second.second == 0 || !paper[i].second) continue;
		int area = (paper[i].first.second.first - paper[i].first.first.first) * 
					(paper[i].first.second.second - paper[i].first.first.second);
		minArea = min(minArea, area);
		maxArea = max(maxArea, area);
	}

	printf("%d %d\n", maxArea, minArea);

	return 0;
}
