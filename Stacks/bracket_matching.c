#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct Stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct Stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
        printf("Cannot Push %c to Stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        printf("Cannot Pop from Stack\n");
        return -1;
    }
    else
    {
        char popped_item = ptr->arr[ptr->top];
        ptr->top--;
        printf("The item %c is Successfully Popped\n", popped_item);
        return popped_item;
    }
} 

int match(char a, char b)
{
    if (a == '[' && b == ']')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else if (a == '(' && b == ')')
        return 1;
    else
        return 0;
}
int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                free(sp->arr);
                free(sp);
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    int result = isEmpty(sp);
    free(sp->arr);
    free(sp);
    return result;
}

int main()
{
    char *exp = "[8*8-{5*5(5+5)]";

    if (parenthesisMatch(exp))
    {
        printf("The Parenthesis are balanced.\n");
    }
    else
    {
        printf("The Parenthesis is are not balanced.\n");
    }

    return 0;
}
