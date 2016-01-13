#include <iostream>

template <typename T>
class Stack
{
	private:
		T stack[10];
		int size;
		int top;
		void exchange(T &data1, T &data2);
	public:
		Stack();
		bool isEmpty();
		bool isFull();
		void push(T data);
		int getTop();
		T pop();
		T peek();
		void printAll();
		void sorting(int (*comp)(T data1, T data2), int start, int end);
};

template <typename T>
Stack<T>::Stack()
{
	size = 10;
	top = -1;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return top == -1;
}

template <typename T>
bool Stack<T>::isFull()
{
	return top == (size - 1);
}

template <typename T>
int Stack<T>::getTop()
{
	return top;
}

template <typename T>
void Stack<T>::push(T data)
{
	if(!isFull())
		this -> stack[++top] = data;
}

template <typename T>
T Stack<T>::pop()
{
	if(!isEmpty())
		return this -> stack[top--];
	else
	{
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}
}

template <typename T>
T Stack<T>::peek()
{
	if(!isEmpty())
		return this -> stack[top];
	else
	{
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}
}

template <typename T>
void Stack<T>::sorting(int (*comp)(T data1, T data2), int start, int end)
{
	int i = start + 1;
	int j = end;
	int pivot = start;

	do
	{
		if(comp(stack[i], stack[pivot]) > 0) { exchange(stack[i], stack[j]); }
		++i;
		if(comp(stack[j], stack[pivot]) > 0) { exchange(stack[j], stack[i]); }
		--j;
	}while(i < j);
	
	if(start < end)
	{
		exchange(stack[pivot], stack[i]);
		quickSort(comp, 0, pivot - 1);
		quickSort(comp, pivot + 1, end);
	}
}

template <typename T>
void Stack<T>::exchange(T &data1, T &data2)
{
	T temp = data1;
	data1 = data2;
	data2 = temp;
}

template <typename T>
void Stack<T>::printAll()
{
	for(int i = 0 ; i <= top ; ++i)
		std::cout << stack[i] << std::endl;
}

int compare(int data1, int data2)
{
	if(data1 > data2) return 1;
	else if(data1 < data2) return -1;
	else return 0;
}

int main()
{
	Stack<int> stack;

	std::cout << "push 10" << std::endl;
	stack.push(10);
	std::cout << "push 30" << std::endl;
	stack.push(30);
	std::cout << "push 20" << std::endl;
	stack.push(20);

	stack.printAll();
	std::cout << "peek: " << stack.peek() << std::endl;
	std::cout << "pop: " << stack.pop() << std::endl;

	std::cout << "push 5" << std::endl;
	stack.push(5);
	stack.printAll();

	stack.sorting(compare, 0, stack.getTop());

	stack.printAll();

	return 0;
}
