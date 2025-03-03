#include <stdio.h>
#include <stdlib.h>

// Node structure for Stack
struct Node {
    int data;
    struct Node *next;
};

// Function to check if Stack is empty
int isEmpty(struct Node *top) {
    return top == NULL;
}

// Function to check if Stack is full (Memory allocation check)
int isFull() {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
        return 1;
    else {
        free(p);
        return 0;
    }
}

// Function to push an element onto the stack
struct Node *push(struct Node *top, int x) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", x);
        return top;
    }
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
    printf("Pushed: %d\n", x);
    return top; // Return the updated top pointer
}

// Function to pop an element from the stack
struct Node *pop(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack Underflow! Cannot pop.\n");
        return top;
    }
    struct Node *n = top;
    top = top->next; // Update the top pointer
    printf("Popped element: %d\n", n->data);
    free(n);
    return top; // Return the updated top pointer
}

// Function to traverse and display the stack
void display(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    struct Node *ptr = top;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to peek at a specific position in the stack
int stackPeek(struct Node *top, int pos) {
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++) {
        ptr = ptr->next;
    }
    if (ptr != NULL)
        return ptr->data;
    else {
        printf("Invalid position: %d\n", pos);
        return -1; // Indicate error
    }
}

// Function to return the top element of the stack
int stackTop(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Function to return the bottom element of the stack
int stackBottom(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return -1;
    }
    struct Node *temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
    }
    return temp->data;
}

// Function to delete the entire stack and free memory
void deleteStack(struct Node *top) {
    while (top != NULL) {
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
    printf("Stack deleted successfully.\n");
}

// Main function with interactive menu
int main() {
    struct Node *top = NULL;
    int choice, value, position;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Peek at Position\n");
        printf("5. Top Element\n");
        printf("6. Bottom Element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
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
                    top = push(top, value);
                }
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Enter position to peek: ");
                if (scanf("%d", &position) != 1 || position <= 0) {
                    printf("Invalid position! Please enter a positive integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                } else {
                    value = stackPeek(top, position);
                    if (value != -1) {
                        printf("Element at position %d is %d\n", position, value);
                    }
                }
                break;
            case 5:
                value = stackTop(top);
                if (value != -1) {
                    printf("Element at the Top is %d\n", value);
                }
                break;
            case 6:
                value = stackBottom(top);
                if (value != -1) {
                    printf("Element at the Bottom is %d\n", value);
                }
                break;
            case 7:
                deleteStack(top);
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1-7.\n");
        }
    }
}
