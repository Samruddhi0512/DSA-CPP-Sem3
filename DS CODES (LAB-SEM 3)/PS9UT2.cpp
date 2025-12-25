/** WAP to create a doubly linked list and perform following operations on it.
 * 1. Insert (all cases) 
 * 2. Delete (all cases). **/

#include <iostream>
using namespace std;

// -------- Node structure --------
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// -------- Create a new node --------
Node* createNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;
    return temp;
}

// -------- Insert at beginning --------
void insertBegin(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

// -------- Insert at end --------
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// -------- Insert after a given value --------
void insertAfter(Node* head, int key, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Key not found!\n";
        return;
    }

    Node* newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// -------- Delete first node --------
void deleteFirst(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
}

// -------- Delete last node --------
void deleteLast(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    if (temp->prev != nullptr)
        temp->prev->next = nullptr;
    else
        head = nullptr;  // only one node

    delete temp;
}

// -------- Delete a node with a given value --------
void deleteValue(Node*& head, int key) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Value not found!\n";
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

// -------- Display the list --------
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {

    Node* head = nullptr;
    int choice, value, key;

    do {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a value\n";
        cout << "4. Delete first\n";
        cout << "5. Delete last\n";
        cout << "6. Delete by value\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertBegin(head, value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertEnd(head, value);
            break;

        case 3:
            cout << "Enter key (after which to insert): ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            insertAfter(head, key, value);
            break;

        case 4:
            deleteFirst(head);
            break;

        case 5:
            deleteLast(head);
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteValue(head, key);
            break;

        case 7:
            display(head);
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}