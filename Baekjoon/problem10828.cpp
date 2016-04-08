#include <cstdio>
#include <string>

class Stack
{
	public:
		Stack() { ptr_top = -1; }
		void push(const int &num) { data[++ptr_top] = num; }
		int pop() { return ptr_top == -1 ? -1 : data[ptr_top--]; }
		int size() { return ptr_top + 1; }
		int empty() { return static_cast<int>(ptr_top == -1); }
		int top() { return ptr_top == -1 ? -1 : data[ptr_top]; }
	private:
		int data[10000];
		int ptr_top;
};

int main()
{
	int n;
	Stack stack;
	scanf("%d", &n);
	getc(stdin);
	while(n--)
	{
		std::string command;
		char buf[13];
		int i = 2;
		fgets(buf, 13, stdin);
		while(buf[++i] != '\n');
		buf[i] ='\0';
		command = buf;
		if(!command.compare("top")) printf("%d\n", stack.top());
		else if(!command.compare("size")) printf("%d\n", stack.size());
		else if(!command.compare("empty")) printf("%d\n", stack.empty());
		else if(!command.compare("pop")) printf("%d\n", stack.pop());
		else stack.push(std::stoi(command.substr(5, command.length() - 5).data()));
	}
	return 0;
}
