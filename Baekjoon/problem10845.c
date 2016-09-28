#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Queue Queue;
struct _Queue
{
	int *data;
	int front;
	int rear;
};
void init(Queue **queue, int size);
void destroy(Queue *queue);
int push(Queue *queue, int data);
int pop(Queue *queue);
bool empty(Queue *queue);
int size(Queue *queue);
int front(Queue *queue);
int back(Queue *queue);

int main()
{
	Queue *queue;
	int n, data;
	char cmd[6];

	scanf("%d", &n);
	init(&queue, n);

	while(n--)
	{
		scanf("%s", cmd);
		switch(cmd[1])
		{
			case 'u':
				scanf("%d", &data);
				push(queue, data);
				break;
			case 'o':
				data = pop(queue);
				printf("%d\n", data);
				break;
			case 'i':
				printf("%d\n", size(queue));
				break;
			case 'm':
				printf("%d\n", empty(queue));
				break;
			case 'r':
				printf("%d\n", front(queue));
				break;
			case 'a':
				printf("%d\n", back(queue));
				break;

		}
	}
	destroy(queue);
	return 0;
}

void init(Queue **queue, int size)
{
	(*queue) = (Queue *)calloc(1, sizeof(queue));
	(*queue) -> data = (int *)calloc(size, sizeof(int));
	(*queue) -> front = 0;
	(*queue) -> rear = 0;
}
void destroy(Queue *queue)
{
	free(queue -> data);
	free(queue);
}
int push(Queue *queue, int data)
{
	(queue -> data)[(queue -> rear)++] = data;
	return queue -> rear - 1;
}
int pop(Queue *queue)
{
	return empty(queue) ? -1 : queue -> data[(queue -> front)++];
}
bool empty(Queue *queue)
{
	return queue -> front == queue -> rear;
}
int size(Queue *queue)
{
	return queue -> rear - queue -> front;
}
int front(Queue *queue)
{
	return empty(queue) ? -1 : queue -> data[queue -> front];
}
int back(Queue *queue)
{
	return empty(queue) ? -1 : queue -> data[queue -> rear - 1];
}
