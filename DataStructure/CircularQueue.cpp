// This code has bug, so it need be debuged

#include<iostream>
#include<cstdlib>
#include<ctime>

template<typename T>
class Queue
{
	private:
		int front;
		int rear;
		int size;
		T queue[11];
		int (*comp)(T data1, T data2);
		void swap(T& data1, T& data2);
	public:
		Queue();
		bool enqueue(T data);
		T dequeue();
		bool isEmpty();
		int getSize();
		void printAll();
		T peek();
		int getRear();
		int getFront();
};

template<typename T>
Queue<T>::Queue()
{
	size = 10;
	front = 0;
	rear = 0;
}
template<typename T>
bool Queue<T>::enqueue(T data)
{
	if((front + 10) % 11 != rear)
	{
		queue[rear] = data;
		rear = (rear + 1) % 11;
	}
	else
	{
		std::cout << "Queue is full" << std::endl;
		return false;
	}
	return true;
}
template<typename T>
T Queue<T>::dequeue()
{
	T data;
	if(!isEmpty())
	{
		data = queue[front];
		queue[front] = 0;
		front = (front + 1) % 11;
		return data;
	}
}
template<typename T>
bool Queue<T>::isEmpty()
{
	return front == rear;
}
template<typename T>
int Queue<T>::getSize()
{
	return size;
}
template<typename T>
void Queue<T>::swap(T& data1, T& data2)
{
	T temp = data1;
	data1 = data2;
	data2 = temp;
}
template<typename T>
void Queue<T>::printAll()
{
	for(int i = 0 ; i < (rear - front + 11) % 11 ; ++i)
	{
		std::cout << queue[(i + front) % 11] << std::endl;
	}
}
template<typename T>
T Queue<T>::peek()
{
	return queue[front];
}
template<typename T>
int Queue<T>::getRear()
{
	return rear;
}
template<typename T>
int Queue<T>::getFront()
{
	return front;
}
int compare(int data1, int data2)
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
	int data;
	Queue<int> queue;
	
	srand((unsigned)time(NULL));

	for(int i = 0 ; i < 10 ; ++i)
	{
		data = rand() % 50;
		std::cout << "Enqueue: ";
		std::cout << data << std::endl;
		queue.enqueue(data);
	}

	queue.printAll();

	for(int i = 0 ; i < 3 ; ++i)
	{
		std::cout << "Dequeue: ";
		std::cout << queue.dequeue() << std::endl;
	}

	for(int i = 0 ; i < 4 ; ++i)
	{
		data = rand() % 50;

		if(queue.enqueue(data))
		{
			std::cout << "Enqueue: ";
			std::cout << data << std::endl;
		}
	}

	std::cout << "Before Sorting" << std::endl;
	queue.printAll();

	queue.sorting(compare);

	std::cout << "After Sorting" << std::endl;
	queue.printAll();
	return 0;
}
