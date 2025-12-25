/** WAP to simulate employee databases as a hash table.
 *  Search a particular faculty by using Mid square method as a hash function 
 * for linear probing method of collision handling technique. Assume suitable data for faculty record. */

 #include <iostream>
#include <cmath>
using namespace std;

class Employee {
public:
    int id;          // key
    string name;
    string dept;

    Employee() {
        id = -1;     // empty
        name = "";
        dept = "";
    }
};

class HashTable {
private:
    int size;
    Employee* table;

public:
    HashTable(int s) {
        size = s;
        table = new Employee[size];
    }

    // -------- Mid-Square Hash Function --------
    int midSquare(int key) {
        long long sq = (long long) key * key;

        string s = to_string(sq);

        int n = s.length();
        int mid = n / 2;

        // Take 2 digits from middle for index
        string midDigits;

        if (n >= 2)
            midDigits = s.substr(mid - 1, 2);
        else
            midDigits = s;    // fallback

        int index = stoi(midDigits);

        return index % size;
    }

    // -------- Insert using Linear Probing --------
    void insert(int id, string name, string dept) {
        int index = midSquare(id);

        // If slot empty → insert
        if (table[index].id == -1) {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;

            cout << "Inserted at index " << index << endl;
            return;
        }

        // Collision → linear probing
        for (int i = 1; i < size; i++) {
            int newIndex = (index + i) % size;

            if (table[newIndex].id == -1) {
                table[newIndex].id = id;
                table[newIndex].name = name;
                table[newIndex].dept = dept;

                cout << "Collision! Inserted at index " << newIndex << endl;
                return;
            }
        }

        cout << "Hash Table FULL! Cannot insert.\n";
    }

    // -------- Search Record --------
    void search(int id) {
        int index = midSquare(id);

        // Check home index
        if (table[index].id == id) {
            printRecord(index);
            return;
        }

        // Linear probe
        for (int i = 1; i < size; i++) {
            int newIndex = (index + i) % size;

            if (table[newIndex].id == id) {
                printRecord(newIndex);
                return;
            }

            if (table[newIndex].id == -1)
                break; // not found
        }

        cout << "Employee NOT found!\n";
    }

    // -------- Print Record --------
    void printRecord(int index) {
        cout << "\nRecord Found at index " << index << ":\n";
        cout << "ID: " << table[index].id
             << "\nName: " << table[index].name
             << "\nDepartment: " << table[index].dept << endl;
    }

    // -------- Display Table --------
    void display() {
        cout << "\n--- Employee Hash Table ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i].id != -1)
                cout << table[i].id << " | " << table[i].name
                     << " | " << table[i].dept;
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};

// ---------------- MAIN ----------------
int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);

    int choice, id;
    string name, dept;

    do {
        cout << "\n--- EMPLOYEE DATABASE MENU ---\n";
        cout << "1. Insert Employee\n2. Search Employee\n3. Display Table\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Department: ";
            cin >> dept;
            ht.insert(id, name, dept);
            break;

        case 2:
            cout << "Enter Employee ID to search: ";
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