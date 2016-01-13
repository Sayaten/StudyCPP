#include <iostream>
#include <cstring>

class Stack
{
	private:
		char stack[10];
		int top;
	public:
		Stack();
		void push(char data);
		char pop();
		int getTop();
		char peek();
		void printAll();
		char* infixToPostfix(char *infix);
		bool isEmpty();
		bool isFull();
};
Stack::Stack()
{
	std::memset(stack, 0, sizeof(char) * 10);
	top = -1;
}
bool Stack::isEmpty()
{
	return top == -1;
}
bool Stack::isFull()
{
	return top == 9;
}
void Stack::push(char data)
{
	if(top == 10)
	{
		std::cout << "stack is full" << std::endl;
	}
	this -> stack[++top] = data;
}
char Stack::pop()
{
	if(top == -1)
	{
		std::cout << "stack is empty" << std::endl;
	}
	return stack[top--];
}
int Stack::getTop()
{
	return top;
}
char Stack::peek()
{
	return stack[top];
}
void Stack::printAll()
{
	for(int i = 0 ; i <= top ; ++i)
	{
		std::cout << stack[i] << std::endl;
	}
}
char* Stack::infixToPostfix(char *infix)
{
	int cnt = 0;
	int len = strlen(infix);
	char *result = new char [len + 1];
	for(int i = 0; i <= len; ++i)
	{
		if('0' <= infix[i] && infix[i] <= '9')
		{
			result[cnt++] = infix[i];
		}
		else if(infix[i] == ' ')
		{
			continue;
		}
		else
		{
			if(infix[i] != '(')
				result[cnt++] = ' ';

			if(isEmpty() || peek() == '(')
			{
				push(infix[i]);
			}
			else
			{
				switch(infix[i])
				{
					case '+':
					case '-':
						if(peek() != '(')
						{
							result[cnt++] = pop();
							result[cnt++] = ' ';
						}
						push(infix[i]);
						break;
					case '*':
					case '/':
						if(peek() == '*' || peek() == '/')
						{
							result[cnt++] = pop();
							result[cnt++] = ' ';
						}
						push(infix[i]);
						break;
					case '(':
						push(infix[i]);
						break;
					case ')':
						while(peek() != '(')
						{
							result[cnt++] = pop();
							result[cnt++] = ' ';
						}
						--cnt;
						pop();
						break;
				}
			}
		}
	}
	while(!isEmpty())
	{
		result[cnt++] = pop();
		result[cnt++] = ' ';
	}
	return result;
}

int main()
{
	Stack stack;
	char *infix, buff[100];
	char *postfix = nullptr;
	int len;

	std::cout << "input infix";
	std::cin.getline(buff, 100);

	std::cout << "infix to postfinx result" << std::endl;
	postfix = stack.infixToPostfix(buff);
	len = strlen(postfix);
	for(int i = 0 ; i <= len ; ++i)
	{	
		//if(!('0' <= postfix[i] && postfix[i] <= '9'))
		//{
		//	std::cout << " " << postfix[i] << " ";
		//}
		std::cout << postfix[i];
	}
	std::cout << std::endl;
	if(postfix != nullptr)
		delete[] postfix;
	//delete[] infix;

	return 0;
}
