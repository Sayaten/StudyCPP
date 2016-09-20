#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct _Node Node;
typedef struct _Deque Deque;
struct _Node
{
	struct _Node *prev;
	struct _Node *next;
	int num;
};
struct _Deque
{
	Node *head;
	Node *tail;
	Node *cur;
	unsigned size;
};
Deque* init();
void destroy(Deque *deque);
Node* push_front(Deque *deque, int num);
Node* push_back(Deque *deque, int num);
int pop_front(Deque *deque);
int pop_back(Deque *deque);
bool empty(Deque *deque);
int front(Deque *deque);
int back(Deque *deque);
unsigned size(Deque *deque);

int main()
{
	char command[11];
	int num, n;
	Deque *deque = init();
	
	scanf("%d", &n);

	while(n--)
	{
		scanf("%s", command);
		switch(command[1])
		{
			case 'u':
				scanf("%d", &num);
				if(command[5] == 'b') push_back(deque, num);
				else if(command[5] == 'f') push_front(deque, num);
				break;
			case 'o':
				num = -1;
				if(command[4] == 'b') num = pop_back(deque);
				else if(command[4] == 'f') num = pop_front(deque);
				printf("%d\n", num);
				break;
			case 'a':
				printf("%d\n", back(deque));
				break;
			case 'r':
				printf("%d\n", front(deque));
				break;
			case 'i':
				printf("%u\n", size(deque));
				break;
			case 'm':
				printf("%d\n", empty(deque));
				break;
		}
	}

	free(deque);
	return 0;
}
Deque* init()
{
	Deque *deque = (Deque *)calloc(1, sizeof(Deque));
	deque -> head = (Node *)calloc(1, sizeof(Node));
	deque -> tail = (Node *)calloc(1, sizeof(Node));

	deque -> head -> prev = deque -> head;
	deque -> head -> next = deque -> tail;
	deque -> tail -> prev = deque -> head;
	deque -> tail -> next = deque -> tail;
	
	deque -> size = 0;

	return deque;
}
void destroy(Deque *deque)
{
	int i;
	deque -> cur = deque -> tail;
	for(i = 0 ; i < deque -> size ; ++i)
	{
		deque -> cur = deque -> cur -> prev;
		free(deque -> cur -> next);
	}
	free(deque -> head);
	free(deque -> tail);
	free(deque);
}
Node* push_front(Deque *deque, int num)
{
	deque -> cur = (Node *)calloc(1, sizeof(Node));

	if(deque -> cur == NULL) return NULL;

	deque -> cur -> prev = deque -> head;
	deque -> cur -> next = deque -> head -> next;
	deque -> head -> next -> prev = deque -> cur;
	deque -> head -> next = deque -> cur;
	deque -> cur -> num = num;

	++(deque -> size);

	return deque -> cur;
}
Node* push_back(Deque *deque, int num)
{
	deque -> cur = (Node *)calloc(1, sizeof(Node));

	if(deque -> cur == NULL) return NULL;

	deque -> cur -> prev = deque -> tail -> prev;
	deque -> cur -> next = deque -> tail;
	deque -> tail -> prev -> next = deque -> cur;
	deque -> tail -> prev = deque -> cur;
	deque -> cur -> num = num;

	++(deque -> size);
	
	return deque -> cur;
}
int pop_front(Deque *deque)
{
	int num;
	
	if(deque -> size == 0) return -1;

	deque -> cur = deque -> head -> next;
	num = deque -> cur -> num;

	deque -> head -> next -> next -> prev = deque -> head;
	deque -> head -> next = deque -> head -> next -> next;

	free(deque -> cur);
	--(deque -> size);

	return num;
}
int pop_back(Deque *deque)
{
	int num;

	if(deque -> size == 0) return -1;

	deque -> cur = deque -> tail -> prev;
	num = deque -> cur -> num;

	deque -> tail -> prev -> prev -> next = deque -> tail;
	deque -> tail -> prev = deque -> tail -> prev -> prev;
	
	free(deque -> cur);
	--(deque -> size);

	return num;
}
bool empty(Deque *deque)
{
	return deque -> size == 0;
}
int front(Deque *deque)
{
	return deque -> size == 0 ? -1 : deque -> head -> next -> num;
}
int back(Deque *deque)
{
	return deque -> size == 0 ? -1 : deque -> tail -> prev -> num;
}
unsigned size(Deque *deque)
{
	return deque -> size;
}
