public class LinkedListOperations {

    // Define the structure for a node
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    Node head;

    // Function to insert a node at the beginning of the list
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Function to insert a node at the end of the list
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    // Function to insert a node after a given node
    public void insertAfter(Node prevNode, int data) {
        if (prevNode == null) {
            System.out.println("Previous node cannot be null.");
            return;
        }
        Node newNode = new Node(data);
        newNode.next = prevNode.next;
        prevNode.next = newNode;
    }

    // Function to delete a node from the beginning
    public void deleteFromBeginning() {
        if (head == null)
            return;
        head = head.next;
    }

    // Function to delete a node from the end
    public void deleteFromEnd() {
        if (head == null)
            return;
        if (head.next == null) {
            head = null;
            return;
        }
        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
    }

    // Function to delete a node from a given position
    public void deleteAtPosition(int position) {
        if (head == null)
            return;
        Node temp = head;

        if (position == 0) {
            head = temp.next;
            return;
        }

        for (int i = 0; temp != null && i < position - 1; i++)
            temp = temp.next;

        if (temp == null || temp.next == null)
            return;

        temp.next = temp.next.next;
    }

    // Function to search for a key in the list
    public boolean search(int key) {
        Node current = head;
        while (current != null) {
            if (current.data == key)
                return true;
            current = current.next;
        }
        return false;
    }

    // Function to reverse the linked list
    public void reverse() {
        Node prev = null;
        Node current = head;
        Node next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Function to get the length of the linked list
    public int getLength() {
        int length = 0;
        Node current = head;
        while (current != null) {
            length++;
            current = current.next;
        }
        return length;
    }

    // Function to detect a cycle in the linked list
    public boolean detectCycle() {
        Node slow = head, fast = head;
        while (slow != null && fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    // Function to merge two sorted linked lists
    public Node mergeSortedLists(Node l1, Node l2) {
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;

        if (l1.data <= l2.data) {
            l1.next = mergeSortedLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeSortedLists(l1, l2.next);
            return l2;
        }
    }

    // Function to find the middle of the linked list
    public Node findMiddle() {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    // Function to remove duplicates from a sorted linked list
    public void removeDuplicates() {
        Node current = head;
        Node next_next;

        if (current == null)
            return;

        while (current.next != null) {
            if (current.data == current.next.data) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
    }

    // Function to print the linked list
    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    // Main function to demonstrate the operations
    public static void main(String[] args) {
        LinkedListOperations list = new LinkedListOperations();

        // Insertions
        list.insertAtBeginning(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);
        list.insertAfter(list.head.next, 25); // Insert after the second node

        System.out.println("Linked list after insertions:");
        list.printList();

        // Deletions
        list.deleteFromBeginning();
        list.deleteAtPosition(1);
        list.deleteFromEnd();

        System.out.println("Linked list after deletions:");
        list.printList();

        // Searching
        int key = 25;
        if (list.search(key))
            System.out.println("Element " + key + " found in the list.");
        else
            System.out.println("Element " + key + " not found in the list.");

        // Reversing
        list.reverse();
        System.out.println("Linked list after reversing:");
        list.printList();

        // Get length
        int length = list.getLength();
        System.out.println("Length of the list: " + length);

        // Detect cycle
        if (list.detectCycle())
            System.out.println("Cycle detected in the list.");
        else
            System.out.println("No cycle detected in the list.");

        // Find middle
        Node middle = list.findMiddle();
        if (middle != null)
            System.out.println("Middle element: " + middle.data);

        // Removing duplicates
        list.insertAtEnd(20);
        list.insertAtEnd(20);
        list.removeDuplicates();
        System.out.println("Linked list after removing duplicates:");
        list.printList();

        // Merging two sorted lists
        LinkedListOperations list1 = new LinkedListOperations();
        LinkedListOperations list2 = new LinkedListOperations();
        list1.insertAtEnd(10);
        list1.insertAtEnd(30);
        list2.insertAtEnd(20);
        list2.insertAtEnd(40);
        Node mergedHead = list.mergeSortedLists(list1.head, list2.head);
        LinkedListOperations mergedList = new LinkedListOperations();
        mergedList.head = mergedHead;
        System.out.println("Merged sorted list:");
        mergedList.printList();
    }
}
