#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

typedef struct Stack
{
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to add an element to the stack (push operation)
void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", value);
        return;
    }
    stack->items[++(stack->top)] = value;
    printf("%d pushed onto the stack.\n", value);
}

// Function to remove an element from the stack (pop operation)
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow! Cannot pop from the stack.\n");
        return -1;
    }
    int poppedItem = stack->items[(stack->top)--];
    printf("%d popped from the stack.\n", poppedItem);
    return poppedItem;
}

// Function to return the top element of the stack (peek operation)
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty! Nothing to peek.\n");
        return -1;
    }
    return stack->items[stack->top];
}

// Function to display the stack
void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements are: \n");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->items[i]);
    }
}

int main()
{
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60); // This will cause stack overflow

    display(&stack);

    printf("Top element is %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);

    display(&stack);

    printf("Top element is %d\n", peek(&stack));

    return 0;
}
