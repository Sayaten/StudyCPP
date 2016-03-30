#include <cstdio>
#include <queue>

struct Node
{
	Node(const int& value, const int& count) : value(value), count(count) { }
	int value;
	int count;
};

int main()
{
	int n;
	bool isCalced[1000000] = { false, };
	std::queue<Node> number;
	scanf("%d", &n);
	number.push(Node(n, 0));
	while(number.front().value != 1)
	{
		if(number.front().value % 2 == 0 && !isCalced[number.front().value / 2]) 
		{ 
			number.push(Node(number.front().value / 2, number.front().count + 1)); 
			isCalced[number.front().value / 2] = 1; 
		}
		if(number.front().value % 3 == 0 && !isCalced[number.front().value / 3]) 
		{ 
			number.push(Node(number.front().value / 3, number.front().count + 1)); 
			isCalced[number.front().value / 3] = 1; 
		}
		if(number.front().value - 1 >= 1 && !isCalced[number.front().value - 1]) 
		{ 
			number.push(Node(number.front().value - 1, number.front().count + 1)); 
			isCalced[number.front().value - 1] = 1; 
		}
		number.pop();
	}
	printf("%d\n", number.front().count);
	return 0;
}
