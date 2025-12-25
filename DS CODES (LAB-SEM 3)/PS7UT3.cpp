/** Pizza parlour accepting maximum n orders. Orders are served on
an FCFS basis. Order once placed can’t be cancelled. Write C++
program to simulate the system using circular QUEUE.**/

/** 
 *                    UNIT 3  QUEUES
 */

 #include <iostream>
using namespace std;

#define MAX 5   // maximum number of pizza orders

class PizzaParlour {
    int orders[MAX];   // array to store orders
    int front, rear;   // queue pointers

public:
    PizzaParlour() {
        front = -1;
        rear = -1;
    }

    // Function to place a new order
    void placeOrder(int orderID) {
        // Check if queue is full
        if ((rear + 1) % MAX == front) {
            cout << "Sorry! No more orders can be accepted (Queue Full).\n";
            return;
        }

        // First order
        if (front == -1)
            front = 0;

        // Move rear in circular manner
        rear = (rear + 1) % MAX;
        orders[rear] = orderID;

        cout << "Order " << orderID << " placed successfully!\n";
    }

    // Function to serve an order
    void serveOrder() {
        if (front == -1) {
            cout << "No orders to serve (Queue Empty).\n";
            return;
        }

        cout << "Order " << orders[front] << " served.\n";

        // If last order served
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Function to display current orders
    void displayOrders() {
        if (front == -1) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Current pending orders: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    PizzaParlour p;
    int choice, orderID;

    cout << "=== PIZZA PARLOUR ORDER SYSTEM ===\n";

    do {
        cout << "\n1. Place Order";
        cout << "\n2. Serve Order";
        cout << "\n3. Display Pending Orders";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                p.placeOrder(orderID);
                break;

            case 2:
                p.serveOrder();
                break;

            case 3:
                p.displayOrders();
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