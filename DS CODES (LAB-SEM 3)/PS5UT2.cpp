/** Write a C++ program to store a binary number using a doubly
linked list. Implement the following functions:
a. Calculate and display the 1’s complement and 2’s complement
of the stored binary number.
b. Perform addition of two binary numbers represented using
doubly linked lists and display the result. **/

#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int bit;
    Node* prev;
    Node* next;
};

class BinaryNumber {
public:
    Node* head;
    Node* tail;

    BinaryNumber() {
        head = tail = NULL;
    }

    // Insert a bit at the end
    void insertBit(int bit) {
        Node* newNode = new Node{bit, NULL, NULL};
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display the binary number
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->bit;
            temp = temp->next;
        }
        cout << endl;
    }

    // a) 1's Complement
    BinaryNumber onesComplement() {
        BinaryNumber result;
        Node* temp = head;
        while (temp) {
            result.insertBit(temp->bit == 0 ? 1 : 0);
            temp = temp->next;
        }
        return result;
    }

    // a) 2's Complement (1's complement + 1)
    BinaryNumber twosComplement() {
        BinaryNumber oneComp = onesComplement();
        Node* temp = oneComp.tail;
        int carry = 1;

        // Add 1 starting from LSB
        while (temp) {
            int sum = temp->bit + carry;
            temp->bit = sum % 2;
            carry = sum / 2;
            temp = temp->prev;
        }

        // If carry remains, add new MSB
        if (carry == 1) {
            Node* newNode = new Node{1, NULL, oneComp.head};
            oneComp.head->prev = newNode;
            oneComp.head = newNode;
        }
        return oneComp;
    }

    // b) Add two binary numbers
    static BinaryNumber add(BinaryNumber b1, BinaryNumber b2) {
        BinaryNumber result;
        Node* p = b1.tail;
        Node* q = b2.tail;
        int carry = 0;

        // Add from LSB to MSB
        while (p || q || carry) {
            int bit1 = (p ? p->bit : 0);
            int bit2 = (q ? q->bit : 0);
            int sum = bit1 + bit2 + carry;

            // Insert result bit at beginning
            Node* newNode = new Node{sum % 2, NULL, result.head};
            if (result.head) result.head->prev = newNode;
            else result.tail = newNode;
            result.head = newNode;

            carry = sum / 2;

            if (p) p = p->prev;
            if (q) q = q->prev;
        }
        return result;
    }
};

int main() {
    BinaryNumber b1, b2;

    int n;
    cout << "Enter number of bits for first binary number: ";
    cin >> n;
    cout << "Enter bits (MSB to LSB): ";
    for (int i = 0; i < n; i++) {
        int bit;
        cin >> bit;
        b1.insertBit(bit);
    }

    cout << "\nStored Binary Number: ";
    b1.display();

    // 1's complement
    BinaryNumber oneComp = b1.onesComplement();
    cout << "1's Complement: ";
    oneComp.display();

    // 2's complement
    BinaryNumber twoComp = b1.twosComplement();
    cout << "2's Complement: ";
    twoComp.display();

    // Second binary for addition
    cout << "\nEnter number of bits for second binary number: ";
    cin >> n;
    cout << "Enter bits (MSB to LSB): ";
    for (int i = 0; i < n; i++) {
        int bit;
        cin >> bit;
        b2.insertBit(bit);
    }

    cout << "\nFirst Binary: ";
    b1.display();
    cout << "Second Binary: ";
    b2.display();

    BinaryNumber sum = BinaryNumber::add(b1, b2);
    cout << "Sum: ";
    sum.display();

    return 0;
}

