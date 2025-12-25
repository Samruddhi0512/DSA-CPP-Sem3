/** In a call center, customer calls are handled on a first-come, firstserved basis. Implement a queue system using Linked list where:
● Each customer call is enqueued as it arrives.
● Customer service agents dequeue calls to assist
customers.
● If there are no calls, the system waits */
/** 
 *                    UNIT 3  QUEUES
 */

 #include <iostream>
#include <string>
using namespace std;

// Node structure for each customer call
struct Node {
    string customerName;  // to store customer's name
    Node* next;           // pointer to next node
};

// Queue class using linked list
class CallCenterQueue {
    Node* front;  // pointer to front of queue (oldest call)
    Node* rear;   // pointer to rear of queue (newest call)

public:
    // Constructor to initialize empty queue
    CallCenterQueue() {
        front = rear = nullptr;
    }

    // Function to add a new call (enqueue)
    void enqueue(string name) {
        Node* newNode = new Node;
        newNode->customerName = name;
        newNode->next = nullptr;

        // If queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Call from " << name << " has been added to the queue.\n";
    }

    // Function to handle (remove) a call (dequeue)
    void dequeue() {
        if (front == nullptr) {
            cout << "No customer calls waiting. System is idle.\n";
            return;
        }

        Node* temp = front;
        cout << "Assisting customer: " << temp->customerName << endl;

        // Move front to next call
        front = front->next;

        // If queue becomes empty
        if (front == nullptr)
            rear = nullptr;

        delete temp; // free memory
    }

    // Function to display all waiting calls
    void display() {
        if (front == nullptr) {
            cout << "No calls in queue.\n";
            return;
        }

        cout << "Current calls waiting: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->customerName << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CallCenterQueue cc;
    int choice;
    string name;

    cout << "=== CALL CENTER QUEUE SYSTEM ===\n";

    do {
        // Menu options
        cout << "\n1. Add Customer Call";
        cout << "\n2. Handle Next Call";
        cout << "\n3. Display Waiting Calls";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                cc.enqueue(name);
                break;

            case 2:
                cc.dequeue();
                break;

            case 3:
                cc.display();
                break;

            case 4:
                cout << "Exiting system. Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}