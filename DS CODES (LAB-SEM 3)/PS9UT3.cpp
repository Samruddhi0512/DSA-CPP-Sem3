/** Write a program to implement multiple queues i.e. two queues
using array and perform following operations on it. A. Add
Queue, B. Delete from Queue, C. Display Queue
 */

 /** 
 *                    UNIT 3  QUEUES
 */

 #include <iostream>
using namespace std;

#define MAX 5   // maximum size for each queue

class MultipleQueue {
    int queue1[MAX], queue2[MAX];  // two separate queues
    int front1, rear1;             // front and rear for queue 1
    int front2, rear2;             // front and rear for queue 2

public:
    // Constructor to initialize all pointers
    MultipleQueue() {
        front1 = rear1 = -1;
        front2 = rear2 = -1;
    }

    // Function to add an element in queue 1 or 2
    void addQueue(int qno, int value) {
        if (qno == 1) {
            // Check if queue 1 is full
            if (rear1 == MAX - 1) {
                cout << "Queue 1 is full!\n";
                return;
            }
            if (front1 == -1) front1 = 0;  // first element
            rear1++;
            queue1[rear1] = value;
            cout << "Added " << value << " to Queue 1.\n";
        }

        else if (qno == 2) {
            // Check if queue 2 is full
            if (rear2 == MAX - 1) {
                cout << "Queue 2 is full!\n";
                return;
            }
            if (front2 == -1) front2 = 0;  // first element
            rear2++;
            queue2[rear2] = value;
            cout << "Added " << value << " to Queue 2.\n";
        }

        else {
            cout << "Invalid queue number!\n";
        }
    }

    // Function to delete (remove) element from queue 1 or 2
    void deleteQueue(int qno) {
        if (qno == 1) {
            if (front1 == -1 || front1 > rear1) {
                cout << "Queue 1 is empty!\n";
                return;
            }
            cout << "Deleted " << queue1[front1] << " from Queue 1.\n";
            front1++;
        }

        else if (qno == 2) {
            if (front2 == -1 || front2 > rear2) {
                cout << "Queue 2 is empty!\n";
                return;
            }
            cout << "Deleted " << queue2[front2] << " from Queue 2.\n";
            front2++;
        }

        else {
            cout << "Invalid queue number!\n";
        }
    }

    // Function to display elements of queue 1 or 2
    void displayQueue(int qno) {
        if (qno == 1) {
            if (front1 == -1 || front1 > rear1) {
                cout << "Queue 1 is empty!\n";
                return;
            }
            cout << "Queue 1 elements: ";
            for (int i = front1; i <= rear1; i++)
                cout << queue1[i] << " ";
            cout << endl;
        }

        else if (qno == 2) {
            if (front2 == -1 || front2 > rear2) {
                cout << "Queue 2 is empty!\n";
                return;
            }
            cout << "Queue 2 elements: ";
            for (int i = front2; i <= rear2; i++)
                cout << queue2[i] << " ";
            cout << endl;
        }

        else {
            cout << "Invalid queue number!\n";
        }
    }
};

int main() {
    MultipleQueue mq;
    int choice, qno, value;

    cout << "=== MULTIPLE QUEUE IMPLEMENTATION ===\n";

    do {
        // Menu
        cout << "\n1. Add to Queue";
        cout << "\n2. Delete from Queue";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter queue number (1 or 2): ";
                cin >> qno;
                cout << "Enter value to add: ";
                cin >> value;
                mq.addQueue(qno, value);
                break;

            case 2:
                cout << "Enter queue number (1 or 2): ";
                cin >> qno;
                mq.deleteQueue(qno);
                break;

            case 3:
                cout << "Enter queue number (1 or 2): ";
                cin >> qno;
                mq.displayQueue(qno);
                break;

            case 4:
                cout << "Exiting program. Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}