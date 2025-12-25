/** Design and implement a smart college placement portal that uses
 *  advanced hashing techniques to efficiently manage student placement records 
 * with high performance and low collision probability, even under dynamic data growth. */

 #include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    string company;

    Student() {
        roll = -1;   // empty slot
        name = "";
        company = "";
    }
};

class PlacementPortal {
private:
    Student* table;
    int size;

public:
    PlacementPortal(int s) {
        size = s;
        table = new Student[size];
    }

    // ---------- Primary Hash (h1) ----------
    int hash1(int key) {
        return key % size;
    }

    // ---------- Secondary Hash (h2) ----------
    int hash2(int key) {
        return 7 - (key % 7);   // ensures step >1
    }

    // ---------- Insert using Double Hashing ----------
    void insert(int roll, string name, string company) {
        int index = hash1(roll);
        int step  = hash2(roll);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * step) % size;

            if (table[newIndex].roll == -1) {   // free slot found
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].company = company;

                cout << "Record inserted at index " << newIndex << endl;
                return;
            }
        }

        cout << "TABLE FULL! Cannot insert record.\n";
    }

    // ---------- Search ----------
    void search(int roll) {
        int index = hash1(roll);
        int step  = hash2(roll);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * step) % size;

            if (table[newIndex].roll == roll) {
                cout << "\nRecord Found:\n";
                cout << "Roll No: " << table[newIndex].roll << endl;
                cout << "Name: " << table[newIndex].name << endl;
                cout << "Company: " << table[newIndex].company << endl;
                return;
            }

            if (table[newIndex].roll == -1)
                break;
        }
        cout << "Record NOT found.\n";
    }

    // ---------- Display ----------
    void display() {
        cout << "\n--- Placement Hash Table ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i].roll == -1)
                cout << "EMPTY\n";
            else
                cout << table[i].roll << " | " << table[i].name
                     << " | " << table[i].company << endl;
        }
    }
};

// ---------------- MAIN PROGRAM ----------------
int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    PlacementPortal portal(size);

    int choice, roll;
    string name, company;

    do {
        cout << "\n--- SMART COLLEGE PLACEMENT PORTAL ---\n";
        cout << "1. Insert Student\n"
             << "2. Search Student\n"
             << "3. Display Records\n"
             << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll No: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Company: ";
            cin >> company;
            portal.insert(roll, name, company);
            break;

        case 2:
            cout << "Enter Roll No to Search: ";
            cin >> roll;
            portal.search(roll);
            break;

        case 3:
            portal.display();
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