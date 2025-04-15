#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack {
    int top;
    int capacity;
    int *array;
};

// Function to create a stack
struct stack* createStack(int capacity) {
    struct stack *s = (struct stack*) malloc(sizeof(struct stack));
    s->top = -1;
    s->capacity = capacity;
    s->array = (int *) malloc(capacity * sizeof(int));
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
struct stack* push(struct stack *s, int toInsert) {
    if (!isFull(s)) {
        s->top++;
        s->array[s->top] = toInsert;
        printf("The Element %d is Successfully Pushed\n", toInsert);
    }
    return s;
}

// Function to pop an element from the stack
int pop(struct stack *s) {
    if (!isEmpty(s)) {
        return s->array[s->top--];
    }
    return -1; // Return -1 if underflow (basic safeguard)
}

// Function to evaluate postfix expression
int evaluatePostfix(char *postfix) {
    struct stack *s = createStack(50);
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(s, postfix[i] - '0'); // Convert char digit to int
        }
        else {
            int val2 = pop(s);
            int val1 = pop(s);
            int result;

            switch (postfix[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': {
                    result = 1;
                    for (int j = 0; j < val2; j++) {
                        result *= val1;
                    }
                    break;
                }
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    return -1;
            }

            push(s, result);
        }
        i++;
    }

    return pop(s);
}

int main() {
    char postfix[50];
    
    printf("Enter the Postfix Expression to Evaluate: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("The Evaluated Result of Postfix Expression %s is: %d\n", postfix, result);

    return 0;
}
