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
	s->head = (struct Node*)malloc(sizeof(struct Node));
	s->head->data = NULL;
	s->head->next = NULL;
	s->top = s->head;
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
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = toInsert;
		newNode->next = s->top;
		s->top = newNode;
	}
	else
	{
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = toInsert;
		newNode->next = NULL;
		s->top = newNode;
	}
	
	return s;
}

int pop(struct stack *s)
{
	if(!isEmpty(s))
	{
		struct Node *temp = s->top;
		
		s->top = s->top->next;
		return (s->array[s->top--]);
	}
}

/*
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
	push(s, 21);
	push(s, 31);
	push(s, 41);
	push(s, 51);
	
	return 0;
}
