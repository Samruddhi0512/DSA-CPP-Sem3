/** Implement Bubble sort using Doubly Linked List**/

#include <iostream>
using namespace std;

// -------- Node of Doubly Linked List --------
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// -------- Create a new Node --------
Node* createNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;
    return temp;
}

// -------- Insert node at end of DLL --------
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;
    newNode->prev = curr;
}

// -------- Display the DLL --------
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// -------- Bubble Sort on DLL --------
void bubbleSort(Node* head) {
    if (head == nullptr) return;

    bool swapped;

    do {
        swapped = false;
        Node* temp = head;

        // Traverse the list
        while (temp->next != nullptr) {

            // Compare current and next node
            if (temp->data > temp->next->data) {

                // Swap data
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;

                swapped = true;  // A swap occurred
            }
            temp = temp->next;
        }

    } while (swapped);  // Repeat until no swaps
}

int main() {

    Node* head = nullptr;
    int n, value;

    // -------- Input List --------
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    // -------- Display Before Sorting --------
    cout << "\nBefore Sorting: ";
    display(head);

    // -------- Bubble Sort --------
    bubbleSort(head);

    // -------- Display After Sorting --------
    cout << "After Bubble Sort: ";
    display(head);

    return 0;
}