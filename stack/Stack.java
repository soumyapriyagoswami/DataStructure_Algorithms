class Stack {
    private static final int MAX = 5;  // Maximum size of the stack
    private int top;
    private int[] items;

    // Constructor to initialize the stack
    public Stack() {
        top = -1;
        items = new int[MAX];
    }

    // Function to check if the stack is full
    public boolean isFull() {
        return top == MAX - 1;
    }

    // Function to check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Function to add an element to the stack (push operation)
    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack Overflow! Cannot push " + value + " onto the stack.");
            return;
        }
        items[++top] = value;
        System.out.println(value + " pushed onto the stack.");
    }

    // Function to remove an element from the stack (pop operation)
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow! Cannot pop from the stack.");
            return -1;
        }
        int poppedItem = items[top--];
        System.out.println(poppedItem + " popped from the stack.");
        return poppedItem;
    }

    // Function to return the top element of the stack (peek operation)
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty! Nothing to peek.");
            return -1;
        }
        return items[top];
    }

    // Function to display the stack
    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty!");
            return;
        }
        System.out.println("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            System.out.println(items[i]);
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();

        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.push(60);  // This will cause stack overflow

        stack.display();

        System.out.println("Top element is " + stack.peek());

        stack.pop();
        stack.pop();
        stack.pop();

        stack.display();

        System.out.println("Top element is " + stack.peek());
    }
}
