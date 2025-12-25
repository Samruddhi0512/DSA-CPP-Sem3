/** Implement collision handling using separate chaining. */

#include <iostream>
#include <vector>
using namespace std;

// -------- Node for Linked List --------
class Node {
public:
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = nullptr;
    }
};

// -------- Hash Table Class --------
class HashTable {
private:
    int size;
    vector<Node*> table;

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table.resize(size, nullptr);
    }

    // Hash Function
    int hash(int key) {
        return key % size;
    }

    // Insert using separate chaining
    void insert(int key) {
        int index = hash(key);

        Node* newNode = new Node(key);

        // insert new node at the beginning of the chain
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Search key
    bool search(int key) {
        int index = hash(key);

        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display entire table
    void display() {
        cout << "\nHash Table (Separate Chaining):\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

// ---------------- MAIN PROGRAM ----------------
int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);

    int choice, key;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (ht.search(key))
                cout << "Key FOUND in table.\n";
            else
                cout << "Key NOT found.\n";
            break;

        case 3:
            ht.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}