#include <cstdio>
#include <cstring>
#include <stack>
int main()
{
	char input[1000002] = { 0, };
	char bomb[37] = { 0, };
	int input_len, bomb_len;

	scanf("%s", input);
	scanf("%s", bomb);

	input_len = strlen(input);
	bomb_len = strlen(bomb);

	std::stack<char> str;

	for(int i = input_len - 1; i >= 0 ; --i)
	{
		str.push(input[i]);
		if(input[i] == bomb[0])
		{
			char temp_str[37] = { 0, };
			int cnt = 0;
			while(!str.empty() && cnt < bomb_len)
			{
				temp_str[cnt++] = str.top();
				str.pop();
			}
			if(cnt != bomb_len || strcmp(temp_str, bomb)) 
				for(int j = cnt - 1 ; j >= 0 ; --j) 
					str.push(temp_str[j]);
		}
	}
	
	if(str.empty()) printf("%s","FRULA"); 
	else 
		while(!str.empty())
		{
			printf("%c", str.top());
			str.pop();
		}
	printf("\n");
	return 0;
}
