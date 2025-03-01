#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Linked List Traversal
void traverse(struct Node* head) {    
    if (head == NULL) {
        printf("\nThe List is Empty!\n");
        return;
    }
    
    printf("\nPrinting Linked List\n");
    int i = 0;
    while (head != NULL) {
        printf("Element at index %d: %d\n", i, head->data);
        head = head->next;
        i++;
    }
    printf("\n");
}

// Insert At Beginning
struct Node* insertAtBeginning(struct Node* head) {
    int toInsert;
    printf("Enter the element to insert at the beginning: ");
    if (scanf("%d", &toInsert) != 1) {
        printf("Invalid input!\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = toInsert;
    newNode->next = head;
    return newNode;
}

// Insert At End
struct Node* insertAtEnd(struct Node* head) {
    int toInsert;
    printf("Enter the element to insert at the end: ");
    if (scanf("%d", &toInsert) != 1) {
        printf("Invalid input!\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = toInsert;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert At Given Index
struct Node* insertAtIndex(struct Node* head) {
    int atIndex, toInsert;
    printf("Enter the index to insert at: ");
    if (scanf("%d", &atIndex) != 1 || atIndex < 0) {
        printf("Invalid index!\n");
        return head;
    }

    printf("Enter the element to insert: ");
    if (scanf("%d", &toInsert) != 1) {
        printf("Invalid input!\n");
        return head;
    }

    if (atIndex == 0) {
        return insertAtBeginning(head);
    }

    struct Node* temp = head;
    for (int i = 1; i < atIndex && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid index!\n");
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = toInsert;
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

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp1 = head;
    struct Node* temp2 = head->next;
    while (temp2->next != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = NULL;
    free(temp2);
    return head;
}

// Delete Node At Given Index
struct Node* deleteAtIndex(struct Node* head) {
    int atIndex;
    printf("Enter the index to delete: ");
    if (scanf("%d", &atIndex) != 1 || atIndex < 0) {
        printf("Invalid index!\n");
        return head;
    }

    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }

    if (atIndex == 0) {
        return deleteFirst(head);
    }

    struct Node* temp1 = head;
    struct Node* temp2 = head->next;
    for (int i = 1; i < atIndex && temp2 != NULL; i++) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp2 == NULL) {
        printf("Invalid index!\n");
        return head;
    }

    temp1->next = temp2->next;
    free(temp2);
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

    printf("Enter the first element of the linked list: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;

    while (isRun) {
        int option_selected;
        printf("\nSelect an operation:\n");
        printf("1. Traverse Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Index\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Last Node\n");
        printf("7. Delete at Index\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &option_selected) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (option_selected) {
            case 1:
                traverse(head);
                break;
            case 2:
                head = insertAtBeginning(head);
                traverse(head);
                break;
            case 3:
                head = insertAtEnd(head);
                traverse(head);
                break;
            case 4:
                head = insertAtIndex(head);
                traverse(head);
                break;
            case 5:
                head = deleteFirst(head);
                traverse(head);
                break;
            case 6:
                head = deleteLast(head);
                traverse(head);
                break;
            case 7:
                head = deleteAtIndex(head);
                traverse(head);
                break;
            case 8:
                isRun = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    // Free allocated memory before exiting
    freeList(head);
    printf("Program terminated.\n");
    return 0;
}
