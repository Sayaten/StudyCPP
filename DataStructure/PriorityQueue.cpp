#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
struct Node
{
	T data;
	Node<T> *prev;
	Node<T> *next;
};

template <typename T>
class PriorityQueue
{
	private:
		Node<T> *head;
		Node<T> *tail;
		Node<T> *cur;
		int (*comp)(T data1, T data2);
		int size;
	public:
		PriorityQueue(int (*comp)(T data1, T data2));
		~PriorityQueue();
		void enqueue(T data);
		T dequeue();
		bool isEmpty();
		int getSize();
		void printAll();
};

template <typename T>
PriorityQueue<T>::PriorityQueue(int (*comp)(T data1, T data2))
{
	head = new Node<T>;
	tail = new Node<T>;

	head -> prev = head;
	head -> next = tail;
	tail -> prev = head;
	tail -> next = tail;	
	cur = nullptr;

	size = 0;

	this -> comp = comp;
}
template <typename T>
void PriorityQueue<T>::enqueue(T data)
{
	Node<T> *temp;
	cur = head -> next;

	while(cur != tail && comp(cur -> data, data) <= 0){ cur = cur -> next; }

	temp = new Node<T>;
	temp -> data = data;
	
	if(cur != tail)
	{
		cur -> prev -> next = temp;
		temp -> prev = cur -> prev;
		cur -> prev = temp;
		temp -> next = cur;
	}
	else
	{
		tail -> prev -> next = temp;
		temp -> prev = tail -> prev;
		temp -> next = tail;
		tail -> prev = temp;
	}
	++size;
}
template <typename T>
T PriorityQueue<T>::dequeue()
{
	Node<T> *temp = tail -> prev;
	T data = temp -> data;
	tail -> prev -> prev -> next = tail;
	tail -> prev = tail -> prev -> prev;

	delete temp;

	--size;
	
	return data;
}
template <typename T>
int PriorityQueue<T>::getSize()
{
	return size;
}
template <typename T>
bool PriorityQueue<T>::isEmpty()
{
	return size == 0;
}
template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	Node<T> *tmp;
	cur = head -> next;
	for(int i = 0 ; i < size ; ++i)
	{
		tmp = cur -> next;
		delete cur;
		cur = tmp;
	}
	delete head;
	delete tail;
}
template <typename T>
void PriorityQueue<T>::printAll()
{
	cur = head;
	for(int i = 1 ; i <= size ; ++i)
	{
		cur = cur -> next;
		std::cout << i << ": "<< cur -> data << std::endl;
	}
	cur = nullptr;
}
int comp(int data1, int data2)
{
	if(data1 > data2)
	{
		return 1;
	}
	else if(data1 < data2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	PriorityQueue<int> list(comp);
	srand((unsigned)time(NULL));
	for(int i = 0 ; i < 10 ; ++i)
	{
		list.enqueue(rand() % 30);
	}
	list.printAll();

	return 0;
}
