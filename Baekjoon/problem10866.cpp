#include <cstdio>
#include <cstring>
#include <deque>

int main()
{
	std::deque<int> d;
	int n;

	scanf("%d", &n);
	while(n--)
	{
		char command[12];
		int num;
		scanf("%s", command);
		if(!strcmp("push_front", command))
		{
			scanf("%d", &num);
			d.push_front(num);
		}
		else if(!strcmp("push_back", command))
		{
			scanf("%d", &num);
			d.push_back(num);
		}
		else if(!strcmp("pop_front", command))
		{
			if(d.empty()) num = -1;
			else
			{
				num = d.front();
				d.pop_front();
			}
			printf("%d\n", num);
		}
		else if(!strcmp("pop_back", command))
		{
			if(d.empty()) num = -1;
			else
			{
				num = d.back();
				d.pop_back();
			}
			printf("%d\n", num);
		}
		else if(!strcmp("size", command)) printf("%d\n", d.size());
		else if(!strcmp("empty", command)) printf("%d\n", d.empty());
		else if(!strcmp("front", command)) printf("%d\n", d.front());
		else if(!strcmp("back", command)) printf("%d\n", d.back());
	}
	return 0;
}
