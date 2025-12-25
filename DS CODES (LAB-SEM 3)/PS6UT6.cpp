/** WAP to simulate a faculty database as a hash table. 
 * Search a particular faculty by using 'divide' as a hash function 
 * for linear probing with chaining without replacement method of collision handling technique.
 *  Assume suitable data for faculty record. */

 #include <iostream>
using namespace std;

// ----------------- Faculty Record -----------------
class Faculty {
public:
    int id;          // key
    string name;
    string dept;

    Faculty() {
        id = -1;     // empty slot
        name = "";
        dept = "";
    }
};

// ----------------- Hash Table Class -----------------
class HashTable {
private:
    int size;
    Faculty* table;
    int* chain;      // chain array to maintain link

public:
    HashTable(int s) {
        size = s;
        table = new Faculty[size];
        chain = new int[size];

        for (int i = 0; i < size; i++)
            chain[i] = -1;    // no link initially
    }

    // Divide method
    int hash(int key) {
        return key % size;
    }

    // Insert using linear probing + chaining (without replacement)
    void insert(int id, string name, string dept) {
        int index = hash(id);

        // Case 1: If slot is empty → place directly
        if (table[index].id == -1) {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            cout << "Inserted at index " << index << endl;
            return;
        }

        // Case 2: Collision → probe to find empty slot
        int newIndex = -1;
        for (int i = 1; i < size; i++) {
            int temp = (index + i) % size;
            if (table[temp].id == -1) {
                newIndex = temp;
                break;
            }
        }

        if (newIndex == -1) {
            cout << "Hash Table Full! Cannot insert.\n";
            return;
        }

        // Update chain link
        int start = index;

        // Move along chain
        while (chain[start] != -1)
            start = chain[start];

        chain[start] = newIndex;

        // Store record
        table[newIndex].id = id;
        table[newIndex].name = name;
        table[newIndex].dept = dept;

        cout << "Inserted with collision at index " << newIndex << endl;
    }

    // Search by Faculty ID
    void search(int id) {
        int index = hash(id);

        // First check home slot
        if (table[index].id == id) {
            cout << "\nRecord Found:\n";
            printRecord(index);
            return;
        }

        // Traverse chain
        int next = chain[index];
        while (next != -1) {
            if (table[next].id == id) {
                cout << "\nRecord Found:\n";
                printRecord(next);
                return;
            }
            next = chain[next];
        }

        cout << "Faculty NOT found!\n";
    }

    // Display One Record
    void printRecord(int index) {
        cout << "Index: " << index
             << "\nID: " << table[index].id
             << "\nName: " << table[index].name
             << "\nDepartment: " << table[index].dept << endl;
    }

    // Display Full Hash Table
    void display() {
        cout << "\n--- Faculty Hash Table ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i].id != -1)
                cout << table[i].id << " | " << table[i].name
                     << " | " << table[i].dept;
            else
                cout << "EMPTY";

            cout << "   Chain → " << chain[i] << endl;
        }
    }
};

// -------------------- MAIN PROGRAM --------------------
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
            cout << "Enter Faculty ID to Search: ";
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