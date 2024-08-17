#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
        return;
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node from a given position
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to search for a key in the list
bool search(struct Node *head, int key)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

// Function to reverse the linked list
void reverse(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to get the length of the linked list
int getLength(struct Node *head)
{
    int length = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

// Function to detect a cycle in the linked list
bool detectCycle(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// Function to merge two sorted linked lists
struct Node *mergeSortedLists(struct Node *l1, struct Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->data <= l2->data)
    {
        l1->next = mergeSortedLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeSortedLists(l1, l2->next);
        return l2;
    }
}

// Function to find the middle of the linked list
struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct Node *head)
{
    struct Node *current = head;
    struct Node *next_next;

    if (current == NULL)
        return;

    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the operations
int main()
{
    struct Node *head = NULL;

    // Insertions
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAfter(head->next, 25); // Insert after the second node

    printf("Linked list after insertions: ");
    printList(head);

    // Deletions
    deleteFromBeginning(&head);
    deleteAtPosition(&head, 1);
    deleteFromEnd(&head);

    printf("Linked list after deletions: ");
    printList(head);

    // Searching
    int key = 25;
    if (search(head, key))
        printf("Element %d found in the list.\n", key);
    else
        printf("Element %d not found in the list.\n", key);

    // Reversing
    reverse(&head);
    printf("Linked list after reversing: ");
    printList(head);

    // Get length
    int length = getLength(head);
    printf("Length of the list: %d\n", length);

    // Detect cycle
    if (detectCycle(head))
        printf("Cycle detected in the list.\n");
    else
        printf("No cycle detected in the list.\n");

    // Find middle
    struct Node *middle = findMiddle(head);
    if (middle != NULL)
        printf("Middle element: %d\n", middle->data);

    // Removing duplicates
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 20);
    removeDuplicates(head);
    printf("Linked list after removing duplicates: ");
    printList(head);

    // Merging two sorted lists
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    insertAtEnd(&head1, 10);
    insertAtEnd(&head1, 30);
    insertAtEnd(&head2, 20);
    insertAtEnd(&head2, 40);
    struct Node *mergedHead = mergeSortedLists(head1, head2);
    printf("Merged sorted list: ");
    printList(mergedHead);

    return 0;
}
