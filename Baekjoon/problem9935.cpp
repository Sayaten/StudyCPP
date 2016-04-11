#include <cstdio>
#include <cstring>
#include <stack>
#include <deque>
int main()
{
	char input[1000002] = { 0, };
	char bomb[37] = { 0, };
	int input_len, bomb_len;

	scanf("%s", input);
	scanf("%s", bomb);

	input_len = strlen(input);
	bomb_len = strlen(bomb);

	std::stack<char> check;
	std::deque< std::pair<int,int> > bomb_pos;
	int cnt = 0, bomb_cnt = 0;

	bomb_pos.push_back(std::pair<int, int>(0, -1));
	while(cnt < input_len)
	{
		if(input[cnt] == bomb[bomb_len - 1])
		{
			int pos = cnt;
			int push_cnt = 0;
			if(bomb_pos.size() > 1 && pos - bomb_pos.back().second < bomb_len)
			{
				while(pos > bomb_pos.back().second) 
				{
					check.push(input[pos--]);
					++push_cnt;
				}
				pos = bomb_pos.back().first - 1;
			}
			while(pos >= 0 && push_cnt < bomb_len)
			{
				check.push(input[pos--]);
				++push_cnt;
			}
			++pos;
			if(check.size() >= bomb_len) 
			{
				char comp_str[bomb_len + 1];
				for(int i = 0 ; i < bomb_len ; ++i)
				{
					comp_str[i] = check.top();
					check.pop();
				}
				comp_str[bomb_len] = '\0';
				if(!strcmp(comp_str, bomb))
				{
					++bomb_cnt;
					input[pos] = '\0';
					bomb_pos.push_back(std::pair<int, int>(pos, cnt));
				}
			}
		}
		++cnt;
	}
	if(bomb_cnt * bomb_len == input_len) printf("%s","FRULA"); 
	else
	{
		cnt = 0;
		while(cnt < input_len - 1) 
		{
			cnt = bomb_pos.front().second + 1;
			bomb_pos.pop_front();		
			if(bomb_pos.front().first <= cnt && cnt <= bomb_pos.front().second) continue;
			printf("%s", input + cnt);
		}
	}
	printf("\n");
	return 0;
}
