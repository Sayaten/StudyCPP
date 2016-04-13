#include <cstdio>
#include <stack>
#include <cstring>

int main()
{
	char bracket[1000000];
	scanf("%s", bracket);

	int len = strlen(bracket);
	std::stack<std::pair<char, int> > s; 

	int cnt = 0;
	for(int i = 0 ; i < len ; ++i)
		if(bracket[i] == '(') s.push(std::pair<char, int>('(', i));
		else
		{
			cnt += (i - s.top().second == 1) ? s.size() - 1 : 1;
			s.pop();
		}
	printf("%d\n", cnt);

	return 0;
}
