#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

int main()
{
	int r, c, ew, eh;
	scanf("%d %d\n", &r, &c);

	char map[r][c + 1];
	int wmap[r][c];
	list< pair<int, pair<int, int> > > q;
	list< pair<int, pair<int, int> > > wq;
	memset(wmap, 0, sizeof(wmap));

	for(int i = 0 ; i < r ; ++i)
		for(int j = 0 ; j <= c ; ++j)
		{
			scanf("%1c", *(map + i) + j);
			if(map[i][j] == '*') wq.push_back(make_pair(1, make_pair(i, j)));
			else if(map[i][j] == 'S') q.push_back(make_pair(1, make_pair(i, j)));
			else if(map[i][j] == 'D') { eh = i; ew = j; }
		}
	while(!wq.empty())
	{
		int i = wq.front().second.first;
		int j = wq.front().second.second;
		int w = wq.front().first;
		wq.pop_front();
		wmap[i][j] = w;
		if(i - 1 >= 0 && map[i - 1][j] == '.' && wmap[i - 1][j] == 0) wq.push_back(make_pair(w + 1, make_pair(i - 1, j)));
		if(i + 1 <  r && map[i + 1][j] == '.' && wmap[i + 1][j] == 0) wq.push_back(make_pair(w + 1, make_pair(i + 1, j)));
		if(j - 1 >= 0 && map[i][j - 1] == '.' && wmap[i][j - 1] == 0) wq.push_back(make_pair(w + 1, make_pair(i, j - 1)));
		if(j + 1 <  c && map[i][j + 1] == '.' && wmap[i][j + 1] == 0) wq.push_back(make_pair(w + 1, make_pair(i, j + 1)));
	}
	int cnt = -1;
	wmap[eh][ew] = 1000000;
	while(!q.empty())
	{
		int i = q.front().second.first;
		int j = q.front().second.second;
		int w = q.front().first;
		q.pop_front();
		if(i == eh && j == ew) { cnt = w; break; }
		map[i][j] = w;
		//printf("%d %d %d\n", i, j, w);
		if(i - 1 >= 0 && map[i - 1][j] > w + 1 && wmap[i - 1][j] > w + 1) q.push_back(make_pair(w + 1, make_pair(i - 1, j)));
		if(i + 1 <  r && map[i + 1][j] > w + 1 && wmap[i + 1][j] > w + 1) q.push_back(make_pair(w + 1, make_pair(i + 1, j)));
		if(j - 1 >= 0 && map[i][j - 1] > w + 1 && wmap[i][j - 1] > w + 1) q.push_back(make_pair(w + 1, make_pair(i, j - 1)));
		if(j + 1 <  c && map[i][j + 1] > w + 1 && wmap[i][j + 1] > w + 1) q.push_back(make_pair(w + 1, make_pair(i, j + 1)));
	}
	if(cnt == -1) printf("KAKTUS\n");
	else printf("%d\n", cnt - 1);

	return 0;
}
