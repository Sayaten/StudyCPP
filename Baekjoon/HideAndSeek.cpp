#include <cstdio>
#include <queue>

struct Node
{
	Node(int pos, int len) : pos(pos), len(len) {}
	int pos;
	int len;
};

int main()
{
	int start, end, cnt;
	bool visited[200000] = {false,};
	std::queue<Node> path;

	scanf("%d %d", &start, &end);

	path.push(Node(start, 0));
	while(true)
	{
		if(path.front().pos == end) break;
		else if( 0 < path.front().pos && !visited[path.front().pos] )
		{
			if(path.front().pos * 2 - end < end - path.front().pos && !visited[path.front().pos * 2])
				path.push(Node(path.front().pos * 2, path.front().len + 1));
			visited[path.front().pos] = true;
		}
		if(path.front().pos - 1 >= 0 && !visited[path.front().pos - 1])
			path.push(Node(path.front().pos - 1, path.front().len + 1));
		if(!visited[path.front().pos + 1])
			path.push(Node(path.front().pos + 1, path.front().len + 1));
		path.pop();
	}
	printf("%d\n", path.front().len);

	return 0;
}
