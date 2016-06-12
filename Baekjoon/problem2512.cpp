#include <cstdio>
#include <vector>

int main()
{
	int n;
	scanf("%d", &n);

	std::vector< int > v;
	int right = 0;
	for(int i = 0 ; i < n ; ++i)
	{
		int value;
		scanf("%d", &value);
		v.push_back( value );
		right = std::max( value, right );
	}
	
	int m;
	scanf("%d", &m);

	int left, middle, answer;
	answer = left = n;
	while(left <= right)
	{
		middle = (left + right) / 2;
		int total = 0;
		for(auto iter = v.begin() ; iter != v.end() ; ++iter)
			total += std::min(middle, *iter);
		if(m < total) right = middle - 1;
		else
		{
			answer = middle;
			if(m > total) left = middle + 1;
			else break;
		}
	}
	printf("%d\n", answer);
	return 0;
}
