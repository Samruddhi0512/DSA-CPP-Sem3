/** WAP to simulate a faculty database as a hash table. Search a particular faculty by using MOD as a hash function for linear
probing method of collision handling technique. Assume suitable data for faculty record. */

#include <iostream>
using namespace std;

class Faculty {
public:
    int id;          // unique faculty ID (used as key)
    string name;
    string dept;

    Faculty() {
        id = -1;     // -1 indicates empty slot
        name = "";
        dept = "";
    }
};

class HashTable {
private:
    int size;
    Faculty *table;

public:
    HashTable(int s) {
        size = s;
        table = new Faculty[size];
    }

    // Hash Function: MOD
    int hash(int key) {
        return key % size;
    }

    // Insert a faculty record
    void insert(int id, string name, string dept) {
        int index = hash(id);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i) % size;

            if (table[newIndex].id == -1) {  // empty slot
                table[newIndex].id = id;
                table[newIndex].name = name;
                table[newIndex].dept = dept;

                cout << "Faculty inserted at index " << newIndex << endl;
                return;
            }
        }

        cout << "Hash Table FULL! Cannot insert record." << endl;
    }

    // Search a faculty by ID
    void search(int id) {
        int index = hash(id);

        for (int i = 0; i < size; i++) {

            int newIndex = (index + i) % size;

            if (table[newIndex].id == id) {
                cout << "\nRecord Found:" << endl;
                cout << "ID: " << table[newIndex].id << endl;
                cout << "Name: " << table[newIndex].name << endl;
                cout << "Department: " << table[newIndex].dept << endl;
                return;
            }

            if (table[newIndex].id == -1)  // empty slot → no chance further
                break;
        }

        cout << "Faculty NOT found!" << endl;
    }

    // Display the hash table
    void display() {
        cout << "\n--- Faculty Hash Table ---\n";
        for (int i = 0; i < size; i++) {
            if (table[i].id != -1)
                cout << i << " : " << table[i].id << " | "
                     << table[i].name << " | " << table[i].dept << endl;
            else
                cout << i << " : EMPTY" << endl;
        }
    }
};

// ---------------- MAIN PROGRAM ----------------
int main() {

    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);

    int choice, id;
    string name, dept;

    do {
        cout << "\n--- FACULTY DATABASE MENU ---\n";
        cout << "1. Insert Faculty\n2. Search Faculty\n3. Display Table\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Faculty ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Department: ";
            cin >> dept;
            ht.insert(id, name, dept);
            break;

        case 2:
            cout << "Enter Faculty ID to search: ";
            cin >> id;
            ht.search(id);
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