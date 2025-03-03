#include <stdio.h>
#include <stdlib.h>

// Stack Structure
struct Stack {
    int top;
    int capacity;
    int *array;
};

// Create Stack
struct Stack* createStack(int capacity) {
    struct Stack *s = (struct Stack*) malloc(sizeof(struct Stack));
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    s->top = -1;
    s->capacity = capacity;
    s->array = (int*) malloc(capacity * sizeof(int));
    if (s->array == NULL) {
        printf("Memory allocation for array failed!\n");
        free(s);
        return NULL;
    }
    return s;
}

// Check if Stack is Empty
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Check if Stack is Full
int isFull(struct Stack *s) {
    return (s->top == s->capacity - 1);
}

// Peek (View Top Element)
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return s->array[s->top];
}

// Push (Insert Element)
void push(struct Stack *s, int toInsert) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d.\n", toInsert);
        return;
    }
    s->array[++s->top] = toInsert;
    printf("Pushed: %d\n", toInsert);
}

// Pop (Remove Top Element)
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    return s->array[s->top--];
}

// Delete Stack (Free Memory)
void deleteStack(struct Stack *s) {
    if (s) {
        free(s->array);
        free(s);
        printf("Stack deleted successfully.\n");
    }
}

int main() {
    int capacity, choice, value;
    
    // Ask user for stack capacity
    printf("Enter the capacity of Stack: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        printf("Invalid input! Stack capacity must be a positive integer.\n");
        return 1;
    }

    struct Stack* s = createStack(capacity);
    if (s == NULL) {
        return 1;
    }

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Check if Stack is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid option.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input! Please enter an integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                } else {
                    push(s, value);
                }
                break;
            case 2:
                value = pop(s);
                if (value != -1) {
                    printf("Popped: %d\n", value);
                }
                break;
            case 3:
                value = peek(s);
                if (value != -1) {
                    printf("Top Element: %d\n", value);
                }
                break;
            case 4:
                printf("Stack is %s.\n", isEmpty(s) ? "Empty" : "Not Empty");
                break;
            case 5:
                printf("Stack is %s.\n", isFull(s) ? "Full" : "Not Full");
                break;
            case 6:
                deleteStack(s);
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1-6.\n");
        }
    }
}
