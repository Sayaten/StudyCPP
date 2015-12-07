#include <iostream>

#define NO_ERR 0
#define ERR_EMPTY 1

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

class Stack
{
	public:
		Stack();
		~Stack();
		void push(int value);
		int pop();
		int top();
		bool isEmpty();
		int getSize();
	private:
		bool checkError();
		Node *head;
		Node *tail;
		Node *cur;
		int size;
};

int main()
{
	Stack stack = Stack();

	stack.push(10);
	std::cout << "push: " << stack.top() << std::endl;
	stack.push(15);
	std::cout << "push: " << stack.top() << std::endl;
	std::cout << "top: " << stack.top() << std::endl;
	std::cout << "size: " << stack.getSize() << std::endl;
	std::cout << "Is empty? " << (stack.isEmpty() ? "true" : "false") << std::endl;
	std::cout << "pop: " << stack.pop() << std::endl;
	std::cout << "pop: " << stack.pop() << std::endl;
	stack.pop();
	std::cout << "Is empty? " << (stack.isEmpty() ? "true" : "false") << std::endl;
	return 0;
}

Stack::Stack()
{
	head = new Node;
	tail = new Node;
	head -> next = tail;
	head -> prev = head;
	tail -> next = tail;
	tail -> prev = head;
	cur = nullptr;
	size = 0;
}

Stack::~Stack()
{
	Node *tmp1 = head -> next;
	for(int i = 0 ; i < size ; ++i)
	{
		cur = tmp1 -> next;
		delete tmp1;
		tmp1 = cur;
	}
	delete head;
	delete tail;
}

void Stack::push(int value)
{
	cur = new Node;
	tail -> prev -> next = cur;
	cur -> prev = tail -> prev;
	cur -> next = tail;
	tail -> prev = cur;
	cur -> data = value;
	++size; 
}

int Stack::pop()
{
	int value;

	if(checkError())
	{
		return 0;
	}

	cur = tail -> prev;
	value = cur -> data;

	tail -> prev -> prev -> next = tail;
	tail -> prev = tail -> prev -> prev;
	delete cur;
	--size;

	return value;
}

int Stack::top()
{
	if(checkError())
	{
		return 0;
	}
	return tail -> prev -> data;
}

bool Stack::isEmpty()
{
	return size == 0;
}

int Stack::getSize()
{
	return size;
}

bool Stack::checkError()
{
	if(isEmpty())
	{
		std::cout<< "No Data!!!" << std::endl;
		return ERR_EMPTY;
	}
	else
	{
		return NO_ERR;
	}
}
