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
class DList
{
	private:
		Node<T> *head;
		Node<T> *tail;
		Node<T> *cur;
		int size;
		void exchange(Node<T>* &node1, Node<T>* &node2);
	public:
		DList();
		~DList();
		bool insertNext(T data);
		bool insertPrev(T data);
		bool remove();
		bool find(T data);
		bool find(Node<T>* node);
		bool findWithIndex(int index);
		bool isEmpty();
		int getSize();
		Node<T>* getCur();
		void sorting(int (*comp)(T data1, T data2));
		void printAll();
};

template <typename T>
DList<T>::DList()
{
	head = new Node<T>;
	tail = new Node<T>;

	head -> prev = head;
	head -> next = tail;
	tail -> prev = head;
	tail -> next = tail;	
	cur = nullptr;

	size = 0;
}

template <typename T>
bool DList<T>::insertPrev(T data)
{
	if(cur == nullptr)
	{
		return false;
	}
	Node<T> *tmp = cur;
	
	cur = new Node<T>;
	cur -> data = data;
	cur -> next = tmp;
	cur -> prev = tmp -> prev;
	tmp -> prev -> next = cur;
	tmp -> prev = cur;

	++size;

	cur = nullptr;
	
	return true;
}

template <typename T>
bool DList<T>::insertNext(T data)
{
	if(cur == nullptr)
	{
		return false;
	}
	Node<T> *tmp = cur;

	cur = new Node<T>;
	cur -> data = data;
	cur -> prev = tmp;
	cur -> next = tmp -> next;
	tmp -> next -> prev = cur;
	tmp -> next = cur;

	++size;

	cur = nullptr;
	
	return true;
}

template <typename T>
bool DList<T>::remove()
{
	if(cur == nullptr)
	{
		return false;
	}

	Node<T> *tmp;

	cur -> prev -> next = cur -> next;
	cur -> next -> prev = cur -> prev;

	delete cur;

	--size;

	cur = nullptr;
	
	return true;
}

template <typename T>
bool DList<T>::find(Node<T>* node)
{
	cur = head;
	for(int i = 0 ; i < size ; ++i)
	{
		cur -> next;
		if(cur == node)
		{
			return true;
		}
	}
	return false;
}
template <typename T>
bool DList<T>::find(T data)
{
	cur = head;
	for(int i = 0 ; i < size ; ++i)
	{
		cur -> next;
		if(cur -> data == data)
		{
			return true;
		}
	}
	return false;
}
template <typename T>
bool DList<T>::findWithIndex(int index)
{
	if(index > size)
	{
		return false;
	}
	cur = head;
	for(int i = 0 ; i < index ; ++i)
	{
		cur = cur -> next;
	}
	return true;
}
template <typename T>
int DList<T>::getSize()
{
	return size;
}
template <typename T>
Node<T>* DList<T>::getCur()
{
	return cur;
}
template <typename T>
bool DList<T>::isEmpty()
{
	return size == 0;
}
template <typename T>
void DList<T>::sorting(int (*comp)(T data1, T data2))
{
	Node<T> *tmp1;
	Node<T> *tmp2;
	for(int i = 1 ; i <= size - 1 ; ++i)
	{
		for(int j = i + 1 ; j <= size ; ++j)
		{
			findWithIndex(i);
			tmp1 = cur;
			findWithIndex(j);
			tmp2 = cur;
			//std::cout << i << ", " << j << " value: "<<tmp1 -> data << " " << tmp2 -> data << std::endl;
			if(comp(tmp1 -> data, tmp2 -> data) > 0)
			{
				exchange(tmp1, tmp2);
			}
		}
	}

	cur = nullptr;
}
template <typename T>
void DList<T>::exchange(Node<T>* &node1, Node<T>* &node2)
{
	//std::cout << "exchange: " << node1 -> data << " " << node2 -> data << std::endl;
	node1 -> prev -> next = node2;
	node2 -> next -> prev = node1;

	if(node1 -> next == node2)
	{
		node1 -> next = node2 -> next;
		node2 -> prev = node1 -> prev;

		node1 -> prev = node2;
		node2 -> next = node1;
	}
	else
	{
		node1 -> next -> prev = node2;
		node2 -> prev -> next = node1;

		cur = node1 -> next;
		node1 -> next = node2 -> next;
		node2 -> next = cur;

		cur = node1 -> prev;
		node1 -> prev = node2 -> prev;
		node2 -> prev = cur;
	}
	//printAll();
	cur = nullptr;
}

template <typename T>
DList<T>::~DList()
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
void DList<T>::printAll()
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
	DList<int> list;
	srand((unsigned)time(NULL));
	for(int i = 0 ; i < 5 ; ++i)
	{
		list.findWithIndex(i);
		list.insertNext(rand() % 50);
	}

	std::cout << list.getSize() << std::endl;
	std::cout << "Before Sorting" << std::endl;
	list.printAll();

	list.sorting(comp);

	std::cout << "\nAfter Sorting" << std::endl;
	list.printAll();
	return 0;
}
