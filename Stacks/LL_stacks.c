#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct stack
{
	struct Node* top;
};

struct stack* createStack()
{
	struct stack *s = (struct stack*) malloc(sizeof(struct stack));
	struct Node *newNode = NULL;
	s->top = newNode;
	return s;
}

int isEmpty(struct stack *s)
{
	return (s->top == NULL);
}

int peek(struct stack *s)
{
	return (s->top->data);
}

struct stack* push(struct stack *s, int toInsert)
{
	if(s!=NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = toInsert;
		newNode->next = s->top;
		s->top = newNode;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = toInsert;
		newNode->next = NULL;
		s->top = newNode;
	}
	
	return s;
}
/*
int pop(struct stack *s)
{
	if(!isEmpty(s))
	{
		struct Node *temp = s->top;
		
		s->top = s->top->next;
		return (s->array[s->top--]);
	}
}

void deleteStack(struct stack *s)
{
	free(s->array);
	free(s);
}
*/

int main()
{
	struct stack* s = createStack();
	if(isEmpty(s))
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("Stack is Not Empty\n");
	}
	push(s, 11);
	if(isEmpty(s))
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("Stack is Not Empty\n");
	}
	push(s, 21);
	push(s, 31);
	push(s, 41);
	push(s, 51);
	printf("The Element At The Top of Stack is %d\n", peek(s));
	return 0;
}
