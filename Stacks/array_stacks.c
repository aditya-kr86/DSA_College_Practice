#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int top;
	int capacity;
	int *array;
};

struct stack* createStack(int capacity)
{
	struct stack *s = (struct stack*) malloc(sizeof(struct stack));
	if(s==NULL)
	{
		return NULL;
	}
	s->top = -1;
	s->capacity = capacity;
	s->array = malloc(capacity*sizeof(int));
	if(!s->array)
	{
		return NULL;
	}
	return s;
}

int isEmpty(struct stack *s)
{	
	return (s->top == -1);
}


int isFull(struct stack *s)
{
	return (s->top+1 == s->capacity);
}

int peek(struct stack *s)
{
	return (s->array[s->top]);
}

struct stack* push(struct stack *s, int toInsert)
{
	if(!isFull(s))
	{	s->top++;
		s->array[s->top] = toInsert;
		printf("The Element %d is Sucessfully Pushed\n", s->array[s->top]);
	}
	return s;
}

int pop(struct stack *s)
{
	if(!isEmpty(s))
	{
		return (s->array[s->top--]);
	}
}


void deleteStack(struct stack *s)
{
	free(s->array);
	free(s);
}

int main()
{
	int capacity;
	printf("Enter the capacity of Stack\n");
	scanf("%d", &capacity);
	struct stack* s = createStack(capacity);
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
	
	if(isFull(s))
	{
		printf("Stack is Full\n");
	}
	else
	{
		printf("Stack is Not Full\n");
	}
	printf("The Element At The Top of Stack is %d\n", peek(s));
	printf("The Element Poped is %d\n", pop(s));
	
	if(isFull(s))
	{
		printf("Stack is Full\n");
	}
	else
	{
		printf("Stack is Not Full\n");
	}
	
	deleteStack(s);
	return 0;
}
