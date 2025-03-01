#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Forward Traversal
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("\nThe List is Empty!\n");
        return;
    }
    
    printf("\nPrinting Doubly Linked List (Forward Traversal)\n");
    int i = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Element at index %d: %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n");
}

// Reverse Traversal
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("\nThe List is Empty!\n");
        return;
    }

    // Move to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nPrinting Doubly Linked List (Reverse Traversal)\n");
    int i = 0;
    while (temp != NULL) {
        printf("Element at reverse index %d: %d\n", i, temp->data);
        temp = temp->prev;
        i++;
    }
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
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    
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
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

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
    for (int i = 1; i < index && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid index!\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

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
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

// Delete Last Node
struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
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
    for (int i = 0; i < index && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid index!\n");
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

// Free memory before exiting
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int isRun = 1, value;
    struct Node* head = NULL;

    printf("Enter the first element of the doubly linked list: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->prev = NULL;
    head->next = NULL;

    while (isRun) {
        int option;
        printf("\nSelect an operation:\n");
        printf("1. Forward Traverse Linked List\n");
        printf("2. Reverse Traverse Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Index\n");
        printf("6. Delete First Node\n");
        printf("7. Delete Last Node\n");
        printf("8. Delete at Index\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &option) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (option) {
            case 1: traverseForward(head); break;
            case 2: traverseBackward(head); break;
            case 3: head = insertAtBeginning(head); break;
            case 4: head = insertAtEnd(head); break;
            case 5: head = insertAtIndex(head); break;
            case 6: head = deleteFirst(head); break;
            case 7: head = deleteLast(head); break;
            case 8: head = deleteAtIndex(head); break;
            case 9: isRun = 0; break;
            default: printf("Invalid choice!\n");
        }
    }

    freeList(head);
    printf("Program terminated.\n");
    return 0;
}
