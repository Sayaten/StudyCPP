#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>

int main()
{
	int n;
	scanf("%d", &n);
	std::priority_queue< std::pair<int, std::string>, std::vector<std::pair<int, std::string> >, std::greater<std::pair<int, std::string> > > lib;

	while(n--)
	{
		char word[51];
		int len;
		scanf("%s", word);
		len = strlen(word);
		lib.push(std::make_pair(len, std::string(word)));
	}
	std::string before;
	while(!lib.empty())
	{
		std::string now = lib.top().second.data();
		lib.pop();
		if(before == now) continue;
		printf("%s\n", now.data());
		before = now;
	}
	return 0;
}
