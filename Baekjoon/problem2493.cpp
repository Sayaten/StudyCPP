#include <cstdio>
#include <stack>

int main()
{
	std::stack< std::pair<int, int> > t;
	int n, pos = 1, height;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &height);
		while(true)
		{
			if(t.empty())
			{
				printf("0 ");
				t.push(std::pair<int, int>(pos, height));
				break;
			}
			else if(t.top().second < height) t.pop();
			else 
			{
				printf("%d ", t.top().first);
				t.push(std::pair<int, int>(pos, height));
				break;
			}
		}
		++pos;
	}
	printf("\n");
}
