// StackDemo.java
import java.util.*;

class StackDemo {
    int top;
    int[] stack;
    int size;

    // Constructor
    StackDemo(int s) {
        size = s;
        stack = new int[size];
        top = -1;
    }

    // Push element
    void push(int val) {
        if (top == size - 1) {
            System.out.println("Stack Overflow!");
        } else {
            stack[++top] = val;
            System.out.println(val + " pushed into stack.");
        }
    }

    // Pop element
    void pop() {
        if (top == -1) {
            System.out.println("Stack Underflow!");
        } else {
            System.out.println(stack[top--] + " popped from stack.");
        }
    }

    // Peek element
    void peek() {
        if (top == -1)
            System.out.println("Stack is empty!");
        else
            System.out.println("Top element: " + stack[top]);
    }

    // Display stack
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

    // Main Method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StackDemo s = new StackDemo(5);
        int choice, val;

        do {
            System.out.println("\n=== STACK MENU ===");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Display");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to push: ");
                    val = sc.nextInt();
                    s.push(val);
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.peek();
                    break;
                case 4:
                    s.display();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 5);

        sc.close();
    }
}
