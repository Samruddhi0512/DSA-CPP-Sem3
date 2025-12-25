/** Implement a hash table with collision resolution using linear probing. */

#include <iostream>
using namespace std;

class HashTable {
    int size;
    int *table;

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new int[size];

        // Initialize all cells with -1 (empty)
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    // Hash function
    int hash(int key) {
        return key % size;
    }

    // Insert key using Linear Probing
    void insert(int key) {
        int index = hash(key);

        // If slot occupied → linear probe
        for (int i = 0; i < size; i++) {
            int newIndex = (index + i) % size;

            if (table[newIndex] == -1) {  // empty slot found
                table[newIndex] = key;
                cout << "Inserted " << key << " at index " << newIndex << endl;
                return;
            }
        }
        cout << "Hash Table Full! Cannot insert.\n";
    }

    // Search key
    int search(int key) {
        int index = hash(key);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i) % size;

            if (table[newIndex] == key)
                return newIndex;

            if (table[newIndex] == -1)
                return -1;  // key not present
        }
        return -1;
    }

    // Display table
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : " << table[i] << endl;
        }
    }
};

// ------------------------ MAIN ------------------------
int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);

    int choice, key;

    do {
        cout << "\n--- HASH TABLE MENU ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
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
            {
                int pos = ht.search(key);
                if (pos == -1)
                    cout << "Key NOT found!\n";
                else
                    cout << "Key found at index " << pos << endl;
            }
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