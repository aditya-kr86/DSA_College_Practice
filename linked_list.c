#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

// Linked List Traversal
void traverse(struct Node* head)
{	
	if(head != NULL)
	{
		int i = 0;
		printf("\nPrinting Linked List\n");
		while (head != NULL)
		{
			printf("The Element at %d index: %d\n",i, head->data);
			head = head->next;
			i++;
		}
	}
	printf("\n");
}

// Insert At Begining
struct Node* insertAtBegining(struct Node* head)
{
	int toInsert;
	printf("Enter The Element That You Want To Insert In The Begining Of LinkedList: ");
	scanf("%d", &toInsert);
	
	struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node));
	firstNode->data = toInsert;
	firstNode->next = head;
	return firstNode;
	
}

// Insert At End
struct Node* insertAtEnd(struct Node* head)
{
	int toInsert;
	printf("Enter The Element That You Want To Insert In The Last Of LinkedList: ");
	scanf("%d", &toInsert);
	
	struct Node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	struct Node* lastNode = (struct Node*)malloc(sizeof(struct Node));
	lastNode->data = toInsert;
	lastNode->next = NULL;
	temp->next = lastNode;
	printf("The Element %d is Successfully Inserted At Last of Linked-List\n", toInsert);
	printf("\n");
	return head;
	
}

// Insert At Given Index
struct Node* insertAtIndex(struct Node* head)
{
	if(head != NULL)
	{
		int atIndex;
		printf("Enter the Index at Which You want to Add new Node: ");
		scanf("%d", &atIndex);
		
		struct Node* temp1 = head;
		struct Node* temp2 = head->next;
		for(int i=1; i<atIndex; i++)
		{
			temp1 = temp1->next;
			if(temp1 == NULL)
			{
				printf("\nInavlid Index!!!!!!!!!!!!!!!!!!!");
				return head;
			}
			temp2 = temp2->next;
		}
		int toInsert;
		printf("\nEnter The Element That You Want To Insert In The Last Of LinkedList: ");
		scanf("%d", &toInsert);
		
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		temp1->next = newNode;
		newNode->data = toInsert;
		newNode->next = temp2;
	}
	return head;
}

// Delete the First Node
struct Node* deleteFirst(struct Node* head)
{
	if(head!= NULL)
	{
		struct Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
}

// Delete the last Node
struct Node* deleteLast(struct Node* head)
{
	if(head!= NULL)
	{
		struct Node* temp1 = head;
		struct Node* temp2 = head->next;
		while(temp2->next != NULL)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		temp1->next = NULL;
		free(temp2);
		return head;
	}
}

// Delete At Given Index
struct Node* deleteAtIndex(struct Node* head)
{
	if(head != NULL)
	{
		int atIndex;
		printf("Enter the Index of Which You want to Delete Node: ");
		scanf("%d", &atIndex);
		struct Node* temp1 = head;
		struct Node* temp2 = head->next;
		for(int i=1; i<atIndex; i++)
		{
			temp1 = temp1->next;
			if(temp1 == NULL)
			{
				printf("\nInavlid Index!!!!!!!!!!!!!!!!!!!");
				return head;
			}
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		free(temp2);
	}
	return head;
}


int main()
{
	int isRun = 1;
	int value;
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter the First Element of Linked List\n");
	scanf("%d", &value);
	head->data = value;
	head->next = NULL;
	while(isRun)
	{
		int option_selected;
		printf("Select The Operation You Want To Perform\n 1.Traversal of Linked List\n 2. Interstion at Begin\n 3. Interstion at End\n 4. Interstion at Index\n 5. Deletion at Begining\n 6. Deletion at End\n 7. Deletion at Index\n OR Enter 8 To Exit The Program\n");
		scanf("%d",&option_selected);
		printf("\n");
		switch(option_selected)
		{
			case 1:
			{
				traverse(head);
				break;
			}
			case 2:
			{
				head = insertAtBegining(head);
				printf("Linked List After Insertion\n");
				traverse(head);
				break;
			}
			case 3:
			{
				head = insertAtEnd(head);
				printf("Linked List After Insertion\n");
				traverse(head);
				break;
			}
			case 4:
			{
				head = insertAtIndex(head);
				printf("Linked List After Insertion\n");
				traverse(head);
				break;
			}
			case 5:
			{
				head = deleteFirst(head);
				printf("Linked List After Deletion\n");
				traverse(head);
				break;
			}
			case 6:
			{
				head = deleteLast(head);
				printf("Linked List After Deletion\n");
				traverse(head);
				break;
			}
			case 7:
			{
				head = deleteAtIndex(head);
				printf("Linked List After Deletion\n");
				traverse(head);
				break;
			}
			case 8:
			{
				isRun = 0;
				break;
			}
			default:
			{
				printf("Invalid Choice");
			}
		};
	}
	
	return 0;
}
