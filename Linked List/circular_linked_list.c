#include <stdio.h>
#include <stdlib.h>

// Circular Linked List Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Circular Linked List Traversal
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("\nThe List is Empty!\n");
        return;
    }

    struct Node* temp = head;
    int i = 0;

    printf("\nPrinting Circular Linked List\n");
    do {
        printf("Element at index %d: %d\n", i, temp->data);
        temp = temp->next;
        i++;
    } while (temp != head);
    printf("\n");
}

// Insert at Beginning
struct Node* insertAtBeginning(struct Node* head) {
    int value;
    printf("Enter the element to insert at the beginning: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

// Insert at End
struct Node* insertAtEnd(struct Node* head) {
    int value;
    printf("Enter the element to insert at the end: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Insert at Given Index
struct Node* insertAtIndex(struct Node* head) {
    int index, value;
    printf("Enter the index to insert at: ");
    if (scanf("%d", &index) != 1 || index < 0) {
        printf("Invalid index!\n");
        return head;
    }

    printf("Enter the element to insert: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        return head;
    }

    if (index == 0) {
        return insertAtBeginning(head);
    }

    struct Node* temp = head;
    for (int i = 1; i < index && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && index > 0) {
        printf("Invalid index!\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Delete First Node
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }

    struct Node* temp = head;
    struct Node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    last->next = head->next;
    head = head->next;
    free(temp);

    return head;
}

// Delete Last Node
struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        free(head);
        return NULL;
    }

    prev->next = head;
    free(temp);

    return head;
}

// Delete Node at Given Index
struct Node* deleteAtIndex(struct Node* head) {
    int index;
    printf("Enter the index to delete: ");
    if (scanf("%d", &index) != 1 || index < 0) {
        printf("Invalid index!\n");
        return head;
    }

    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }

    if (index == 0) {
        return deleteFirst(head);
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 0; i < index && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && index > 0) {
        printf("Invalid index!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

// Free memory before exiting
void freeList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    struct Node* nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}

int main() {
    int isRun = 1, value;
    struct Node* head = NULL;

    printf("Enter the first element of the circular linked list: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = head; // Circular reference

    while (isRun) {
        int option;
        printf("\nSelect an operation:\n");
        printf("1. Traverse Circular Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Index\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Last Node\n");
        printf("7. Delete at Index\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &option) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (option) {
            case 1: traverse(head); break;
            case 2: head = insertAtBeginning(head); break;
            case 3: head = insertAtEnd(head); break;
            case 4: head = insertAtIndex(head); break;
            case 5: head = deleteFirst(head); break;
            case 6: head = deleteLast(head); break;
            case 7: head = deleteAtIndex(head); break;
            case 8: isRun = 0; break;
            default: printf("Invalid choice!\n");
        }
    }

    freeList(head);
    printf("Program terminated.\n");
    return 0;
}
