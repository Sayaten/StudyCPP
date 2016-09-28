#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Stack Stack;
struct _Stack
{
	int *data;
	int top;
};
void init(Stack **stack, int size);
void destory(Stack *stack);
int push(Stack *stack, int data);
int pop(Stack *stack);
bool empty(Stack *stack);
int size(Stack *stack);
int top(Stack *stack);

int main()
{
	Stack *stack;
	int n, data;
	char cmd[6];

	scanf("%d", &n);
	init(&stack, n);

	while(n--)
	{
		scanf("%s", cmd);
		switch(cmd[0])
		{
			case 'p':
				if(cmd[1] == 'u')
				{
					scanf("%d", &data);
					push(stack, data);
				}
				else
				{
					data = pop(stack);
					printf("%d\n", data);
				}
				break;
			case 's':
				printf("%d\n", size(stack));
				break;
			case 'e':
				printf("%d\n", empty(stack));
				break;
			case 't':
				printf("%d\n", top(stack));
				break;
		}
	}

	return 0;
}

void init(Stack **stack, int size)
{
	(*stack) = (Stack *)calloc(1, sizeof(Stack));
	(*stack) -> data = (int *)calloc(size, sizeof(int));
	(*stack) -> top = -1;
}
void destory(Stack *stack)
{
	free(stack -> data);
	free(stack);
}
int push(Stack *stack, int data)
{
	(stack -> data)[++(stack -> top)] = data;
	return stack -> top;
}
int pop(Stack *stack)
{
	return stack -> top == -1 ? -1 : stack -> data[(stack -> top)--];
}
bool empty(Stack *stack)
{
	return stack -> top == -1;
}
int size(Stack *stack)
{
	return stack -> top + 1;
}
int top(Stack *stack)
{
	return stack -> top == -1 ? -1 : stack -> data[stack -> top];
}
