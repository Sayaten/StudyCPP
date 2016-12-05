#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Data
{
	Data(char *name, int korean, int english, int math)
		: korean(korean), english(english), math(math)
	{
		this -> name = name;
	}
	string name;
	int korean;
	int english;
	int math;
};

class Comp
{
	public:
		bool operator() (const Data &lhs, const Data &rhs)
		{
			if(lhs.korean < rhs.korean) return true;
			else if(lhs.korean == rhs.korean)
			{
				if(lhs.english > rhs.english) return true;
				else if(lhs.english == rhs.english)
				{
					if(lhs.math < rhs.math) return true;
					else if(lhs.math == rhs.math)
					{
						return lhs.name.compare(rhs.name) > 0;
					}
				}
			}
			return false;
		}
};

int main()
{
	int n;
	scanf("%d", &n);

	priority_queue < Data, vector<Data>, Comp > pq;
	
	for(int i = 0 ; i < n ; ++i)
	{
		char name[11];
		int korean, english, math;
		scanf("%s", name);
		scanf("%d %d %d", &korean, &english, &math);

		Data temp(name, korean, english, math);
		pq.push(temp);
	}
	
	while(n--)
	{
		Data data = pq.top();
		pq.pop();
		printf("%s\n", data.name.data());
	}

	return 0;
}
