#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of queue

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return rear == SIZE - 1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Enqueue (insert)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " inserted into queue.\n";
    }

    // Dequeue (remove)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " removed from queue.\n";
        front++;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    cout << "=== Queue using Class ===\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
