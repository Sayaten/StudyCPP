#include <cstdio>
#include <list>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	list<int> l;
	list<char> r;
	vector<int> v;

	for(int i = 0 ; i < n ; ++i)
	{
		int num;
		scanf("%d", &num);
		l.push_front(num);
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		v.push_back(i);
		r.push_back('+');
		while(!v.empty() && v.back() == l.back())
		{
			v.pop_back();
			l.pop_back();
			r.push_back('-');
		}
	}

	if(!v.empty() || !l.empty())
		printf("NO\n");
	else
		for(auto e : r) printf("%c\n", e);
	return 0;
}
