#include <cstdio>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Data
{
	Data(int age, char *name, int order)
		: age(age), name(name), order(order)
	{}

	int age;
	int order;
	string name;
};

class Comp
{
	public:
		bool operator() (const Data &lhs, const Data &rhs)
		{
			if(lhs.age > rhs.age) return true;
			else if(lhs.age == rhs.age) return lhs.order > rhs.order;
			return false;
		}
};

int main()
{
	priority_queue< Data,vector< Data >, Comp > pq;
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; ++i)
	{
		int age;
		char name[101];

		scanf("%d", &age);
		scanf("%s", name);

		pq.push(Data(age, name, i));
	}

	for(int i = 0 ; i < n ; ++i)
	{
		printf("%d %s\n", pq.top().age, pq.top().name.data());
		pq.pop();
	}

	return 0;
}
