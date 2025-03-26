// Write C Program To Convert Infix To PostFix using Stacks
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct stack {
    int top;
    int capacity;
    char *array;
};

// Function to create a stack
struct stack* createStack(int capacity) {
    struct stack *s = (struct stack*) malloc(sizeof(struct stack));
    if (s == NULL) {
        return NULL;
    }
    s->top = -1;
    s->capacity = capacity;
    s->array = (char *) malloc(capacity * sizeof(char));
    if (!s->array) {
        return NULL;
    }
    return s;
}

// Function to check if the stack is full
int isFull(struct stack *s) {
    return s->top == s->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct stack *s) {
    return s->top == -1;
}

// Function to push an element to the stack
struct stack* push(struct stack *s, char toInsert) {
    if (!isFull(s)) {
        s->top++;
        s->array[s->top] = toInsert;
        printf("The Element %c is Successfully Pushed\n", s->array[s->top]);
    }
    return s;
}

// Function to pop an element from the stack
char pop(struct stack *s) {
    if (!isEmpty(s)) {
        return (s->array[s->top--]);
    }
    return '\0';
}

// Function to check if a character is an operator
int isOperator(char oper) {
    char operands[7] = {'+', '-', '*', '/', '(', ')', '^'};
    for (int i = 0; i < 7; i++) {
        if (operands[i] == oper) {
            return 1;
        }
    }
    return 0; // Return 0 if not an operator
}

// Function to check the precedence of operators
int checkPrecedence(char infix, char top) {
    if (top == '^' && (infix == '+' || infix == '-' || infix == '*' || infix == '/')) {
        return 1;
    }
    if ((top == '/' || top == '*') && (infix == '+' || infix == '-')) {
        return 1;
    }
    return 0;
}

// Function to get the top element of the stack without popping it
char peek(struct stack *s) {
    if (!isEmpty(s)) {
        return s->array[s->top];
    }
    return '\0';
}

int main() {
    char infix[50];
    char postfix[50];
    
    struct stack* s = createStack(50);

    printf("Enter the Equation to Which you want Postfix Conversion: ");
    scanf("%s", infix);
    
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j] = infix[i];
            j += 1;
        } 
        else if (infix[i] == '(') {
            push(s, infix[i]);
        } 
        else if (infix[i] == ')') {
            while (peek(s) != '(') {
                postfix[j] = pop(s);
                j += 1;
            }
            pop(s);
        }
        else if (isOperator(infix[i])) {
            while (!isEmpty(s) && checkPrecedence(infix[i], peek(s))) {
                postfix[j] = pop(s);
                j += 1;
            }
            push(s, infix[i]);
        }
        i += 1;
    }

    // Pop remaining operators from the stack
    while (!isEmpty(s)) {
        postfix[j] = pop(s);
        j += 1;
    }

    postfix[j] = '\0';
    printf("The Infix expression %s in Postfix is: %s\n", infix, postfix);

    return 0;
}
