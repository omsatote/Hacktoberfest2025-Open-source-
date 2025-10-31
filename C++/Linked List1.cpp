#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at the beginning
    void insertBegin(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Delete a node by value
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        // If the node to delete is the head
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node with value " << val << "\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Value not found!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << "Deleted node with value " << val << "\n";
    }

    // Search for a value
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Value " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value not found in the list.\n";
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor (frees memory)
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    LinkedList list;
    int choice, val;

    cout << "=== Singly Linked List Operations ===\n";

    do {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete a Node";
        cout << "\n4. Search a Value";
        cout << "\n5. Display List";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertBegin(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertEnd(val);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> val;
            list.search(val);
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
