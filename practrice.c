#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int data)
{
    struct Node *newnode = CreateNode(data);
    newnode->next = *top;
    *top = newnode;
}

int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
    }
    int data = (*top)->data;
    struct Node *temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

int peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is Empty.\n");
        return -1;
    }
    return top->data;
}

int isEmpty(struct Node *top)
{
    return top == NULL;
}

void DisplayStack(struct Node *top)
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("Stack after pushes : \n");
    DisplayStack(top);

    printf("Popped element is %d\n", pop(&top));
    printf("Stack after pop: ");
    DisplayStack(top);
    return 0;
}