#include <cstdio>
#include <cstring>
#include <stack>
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		char str[1000001];
		int len;
		std::stack<char> input;
		std::stack<char> backup;
		scanf("%s", str);
		len = strlen(str);

		for(int i = 0 ; i < len ; ++i)
		{
			switch(str[i])
			{
				case '<':
					if(!input.empty())
					{
						backup.push(input.top());
						input.pop();
					}
					break;
				case '>':
					if(!backup.empty())
					{
						input.push(backup.top());
						backup.pop();
					}
					break;
				case '-':
					if(!input.empty()) input.pop();
					break;
				default:
					input.push(str[i]);
					break;
			}
		}
		while(!backup.empty()) 
		{
			input.push(backup.top());
			backup.pop();
		}
		char temp[input.size() + 1];
		temp[input.size()] = '\0';
		while(!input.empty())
		{
			temp[input.size() - 1] = input.top();
			input.pop();
		}
		printf("%s\n", temp);
	}
	return 0;
}
