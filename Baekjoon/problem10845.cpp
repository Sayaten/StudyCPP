#include <cstdio>
#include <cstring>
#include <queue>
int main()
{
	std::queue<int> q;
	int n;

	scanf("%d", &n);
	while(n--)
	{
		char command[12];
		int input;

		scanf("%s", command);
		if     (!strcmp("size",  command)) printf("%d\n", q.size());
		else if(!strcmp("pop",   command)) 
		{
			int output;
			if(q.empty()) output = -1;
			else
			{
				output  = q.front();
				q.pop();
			}
			printf("%d\n", output);
		}
		else if(!strcmp("empty", command)) printf("%d\n", q.empty());
		else if(!strcmp("front", command)) printf("%d\n", q.empty() ? -1 : q.front());
		else if(!strcmp("back",  command)) printf("%d\n", q.empty() ? -1 : q.back());
		else
		{
			scanf("%d", &input);
			q.push(input);
		}
	}

	return 0;
}
