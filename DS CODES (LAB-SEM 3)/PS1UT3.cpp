/** WAP to build a simple stock price tracker that keeps a history of daily stock prices entered by the user. To allow users to go back and view or remove the most recent price, implement a stack using a linked list to store these integer prices. 
Implement the following operations: 
1.	record(price) – Add a new stock price (an integer) to the stack. 
2.	remove() – Remove and return the most recent price (top of the stack). 
3.	latest() – Return the most recent stock price without removing it. 
4.	isEmpty() – Check if there are no prices recorded. 
  */

   /** 
 *                    UNIT 3  STACK
 */

 #include <iostream>
using namespace std;

// Node structure for stack
struct Node {
    int price;
    Node* next;
};

// Stack class using linked list
class StockStack {
private:
    Node* top; // points to the top of stack

public:
    // Constructor
    StockStack() {
        top = NULL;
    }

    // 1. record(price): Push a new price onto the stack
    void record(int price) {
        Node* newNode = new Node;
        newNode->price = price;
        newNode->next = top;
        top = newNode;
        cout << "Recorded stock price: " << price << endl;
    }

    // 2. remove(): Pop the most recent price
    void remove() {
        if (isEmpty()) {
            cout << "No prices to remove! Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Removed most recent price: " << temp->price << endl;
        top = top->next;
        delete temp;
    }

    // 3. latest(): Peek the most recent price
    void latest() {
        if (isEmpty()) {
            cout << "No prices recorded yet.\n";
            return;
        }
        cout << "Most recent stock price: " << top->price << endl;
    }

    // 4. isEmpty(): Check if stack is empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Display all recorded prices (for testing)
    void display() {
        if (isEmpty()) {
            cout << "No prices recorded.\n";
            return;
        }
        cout << "Stock Price History (Top to Bottom): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->price << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function with a menu-driven interface
int main() {
    StockStack s;
    int choice, price;

    do {
        cout << "\n--- Stock Price Tracker ---\n";
        cout << "1. Record new price\n";
        cout << "2. Remove most recent price\n";
        cout << "3. Show latest price\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Display all prices\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stock price: ";
            cin >> price;
            s.record(price);
            break;
        case 2:
            s.remove();
            break;
        case 3:
            s.latest();
            break;
        case 4:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;
        case 5:
            s.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
