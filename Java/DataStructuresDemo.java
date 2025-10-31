// DataStructuresDemo.java
import java.util.*;

// 1️⃣ Stack Implementation using Array
class StackDS {
    int top;
    int[] stack;
    int size;

    StackDS(int s) {
        size = s;
        stack = new int[size];
        top = -1;
    }

    void push(int val) {
        if (top == size - 1) {
            System.out.println("Stack Overflow!");
        } else {
            stack[++top] = val;
            System.out.println(val + " pushed to stack.");
        }
    }

    void pop() {
        if (top == -1) {
            System.out.println("Stack Underflow!");
        } else {
            System.out.println(stack[top--] + " popped from stack.");
        }
    }

    void display() {
        if (top == -1) {
            System.out.println("Stack is empty!");
            return;
        }
        System.out.print("Stack elements: ");
        for (int i = 0; i <= top; i++)
            System.out.print(stack[i] + " ");
        System.out.println();
    }
}

// 2️⃣ Queue Implementation using Array
class QueueDS {
    int front, rear, size;
    int[] queue;

    QueueDS(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    void enqueue(int val) {
        if (rear == size - 1) {
            System.out.println("Queue Overflow!");
        } else {
            if (front == -1) front = 0;
            queue[++rear] = val;
            System.out.println(val + " added to queue.");
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            System.out.println("Queue Underflow!");
        } else {
            System.out.println(queue[front++] + " removed from queue.");
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            System.out.println("Queue is empty!");
            return;
        }
        System.out.print("Queue elements: ");
        for (int i = front; i <= rear; i++)
            System.out.print(queue[i] + " ");
        System.out.println();
    }
}

// 3️⃣ Singly Linked List
class LinkedListDS {
    class Node {
        int data;
        Node next;
        Node(int val) { data = val; next = null; }
    }

    Node head = null;

    void insertEnd(int val) {
        Node newNode = new Node(val);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = newNode;
    }

    void deleteNode(int val) {
        if (head == null) {
            System.out.println("List is empty!");
            return;
        }
        if (head.data == val) {
            head = head.next;
            System.out.println(val + " deleted from list.");
            return;
        }
        Node temp = head;
        while (temp.next != null && temp.next.data != val)
            temp = temp.next;
        if (temp.next == null)
            System.out.println("Value not found!");
        else {
            temp.next = temp.next.next;
            System.out.println(val + " deleted from list.");
        }
    }

    void display() {
        if (head == null) {
            System.out.println("List is empty!");
            return;
        }
        Node temp = head;
        System.out.print("Linked List: ");
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
}

// 4️⃣ Binary Search Tree (BST)
class BST {
    class Node {
        int data;
        Node left, right;
        Node(int val) { data = val; left = right = null; }
    }

    Node root;

    BST() { root = null; }

    void insert(int val) {
        root = insertRec(root, val);
    }

    Node insertRec(Node root, int val) {
        if (root == null)
            return new Node(val);
        if (val < root.data)
            root.left = insertRec(root.left, val);
        else if (val > root.data)
            root.right = insertRec(root.right, val);
        return root;
    }

    void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    void display() {
        System.out.print("Inorder Traversal (Sorted): ");
        inorder(root);
        System.out.println();
    }
}

// 5️⃣ Main Class — Demo of All DS
public class DataStructuresDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StackDS stack = new StackDS(5);
        QueueDS queue = new QueueDS(5);
        LinkedListDS list = new LinkedListDS();
        BST bst = new BST();

        int choice, val;

        do {
            System.out.println("\n=== DATA STRUCTURES MENU ===");
            System.out.println("1. Stack");
            System.out.println("2. Queue");
            System.out.println("3. Linked List");
            System.out.println("4. Binary Search Tree");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("\n-- Stack Operations --");
                    stack.push(10);
                    stack.push(20);
                    stack.push(30);
                    stack.display();
                    stack.pop();
                    stack.display();
                    break;

                case 2:
                    System.out.println("\n-- Queue Operations --");
                    queue.enqueue(1);
                    queue.enqueue(2);
                    queue.enqueue(3);
                    queue.display();
                    queue.dequeue();
                    queue.display();
                    break;

                case 3:
                    System.out.println("\n-- Linked List Operations --");
                    list.insertEnd(100);
                    list.insertEnd(200);
                    list.insertEnd(300);
                    list.display();
                    list.deleteNode(200);
                    list.display();
                    break;

                case 4:
                    System.out.println("\n-- Binary Search Tree Operations --");
                    bst.insert(50);
                    bst.insert(30);
                    bst.insert(70);
                    bst.insert(20);
                    bst.insert(60);
                    bst.display();
                    break;

                case 5:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 5);

        sc.close();
    }
}
