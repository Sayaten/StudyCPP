#include <iostream>
#include <ctime>
#include <cstdlib>

template<typename T>
class Heap
{
	private:
		T data[16];
		int size;
		void swap(T &data1, T &data2);
		int (*comp)(T data1, T data2);
	public:
		Heap(int (*comp)(T data1, T data2));
		void insert(T data);
		void remove(int no);
		void printAll();
		bool isEmpty();
		bool isFull();
		int getSize();
};

template<typename T>
Heap<T>::Heap(int (*comp)(T data1, T data2))
{
	size = 0;
	this -> comp = comp;
}
template<typename T>
void Heap<T>::swap(T &data1, T &data2)
{
	T temp = data1;
	data1 = data2;
	data2 = temp;
}
template<typename T>
void Heap<T>::insert(T data)
{
	int cnt;
	this -> data[++size] = data;
	cnt = size;
	while(cnt / 2 >= 1)
	{
		if(comp(this -> data[cnt], this -> data[cnt / 2]) > 0) 
			swap(this -> data[cnt], this -> data[cnt / 2]);
		else break;
		cnt /= 2;
	}
}
template<typename T>
void Heap<T>::remove(int no)
{
	T temp = data[size--];
	int change, cnt = no;
	T left, right;

	data[size + 1] = 0;
	data[no] = temp;

	while(cnt * 2 <= size)
	{
		if(comp(data[cnt], data[cnt * 2]) < 0) change = cnt * 2;
		else change = cnt;
		if(cnt * 2 + 1 <= size && comp(data[change], data[cnt * 2 + 1]) < 0) 
			change = cnt * 2 + 1;
		if(change == cnt) break;
		else
		{
			swap(data[change], data[cnt]);
			cnt = change;
		}
	}
}
template<typename T>
void Heap<T>::printAll()
{
	std::cout << "Level First Print" << std::endl;
	for(int i = 1 ; i <= size ; ++i)
	{
		std::cout << i << ": " << data[i] << std::endl;
	}
}
template<typename T>
bool Heap<T>::isEmpty()
{
	return size == 0;
}
template<typename T>
bool Heap<T>::isFull()
{
	return size == 15;
}
template<typename T>
int Heap<T>::getSize()
{
	return size;
}

int comp(int data1, int data2)
{
	if(data1 > data2) return 1;
	else if(data1 < data2) return -1;
	else return 0;
}

int main()
{
	Heap<int> heap(comp);

	srand((unsigned)time(NULL));
	for(int i = 0 ; i < 15 ; ++i)
	{
		heap.insert(rand() % 100);
	}
	heap.printAll();
	heap.remove(1);
	heap.printAll();
	return 0;
}
