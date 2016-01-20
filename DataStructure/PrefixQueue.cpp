#include <iostream>
#include <cstring>

class Queue
{
	private:
		char queue[10];
		int front;
		int rear;
	public:
		Queue();
		void enqueue(char data);
		char dequeue();
		bool isEmpty();
		bool isFull();
		int getFront();
		int getRear();
		char peek();
		char* infixToPrefix(char *);
};
Queue::Queue()
{
	front = 0;
	rear = 0;
	std::memset(queue, 0, sizeof(char) * 10);
}
void Queue::enqueue(char data)
{
	if(isFull())
	{
		std::cout << "Queue is full" << std::endl;
		return;
	}
	queue[(rear + 11) % 10] = data;
}
char Queue::dequeue()
{
	char data;
	if(isEmpty())
	{
		std::cout << "Queue is empty" << std::endl;
		return '\n';
	}
	data = queue[front];
	front = (front + 11) % 10;
	return data;
}
bool Queue::isEmpty()
{
	if((rear - front + 10) % 10 == 0)
	{
		return true;
	}
	return false;
}
bool Queue::isFull()
{
	if((rear + 11) % 10 == front)
	{
		return true;
	}
	return false;
}
int Queue::getFront()
{
	return front;
}
int Queue::getRear()
{
	return rear;
}
char Queue::peek()
{
	return queue[(rear + 9) % 10];
}
char* Queue::infixToPrefix(char *infix)
{
	int cnt = 0;
	int len = strlen(infix);
	char *result = new char [len + 1];
	for(int i = 0 ; i <= len ; ++i)
	{
		if('0' <= infix[i] && infix[i] <= '9' || infix[i] == ' ')
		{
			continue;
		}
		else
		{

		}
	}
	
	return result;
}

int main()
{
	Queue queue;
	char buff[100];
	char *prefix = nullptr;
	int len;

	std::cout << "input infix";
	std::cin >> buff;

	std::cout << std::endl;

	std::cout << "Infix to prefix result" << std::endl;
	prefix = queue.infixToPrefix(buff);
	len = strlen(prefix);
	for(int i = 0 ; i <= len ; ++i)
	{
		std::cout << prefix[i];
	}
	std::cout << std::endl;
	if(prefix != nullptr)
		delete[] prefix;

	return 0;
}
