/** Store and retrieve student records using roll numbers. */

#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;

    // method to input student details
    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    // method to display details
    void display() {
        cout << "Roll: " << roll
             << ", Name: " << name
             << ", Marks: " << marks << endl;
    }
};

class StudentRecords {
private:
    Student s[50];   // stores up to 50 students
    int count;

public:
    StudentRecords() {
        count = 0;
    }

    // Store student
    void addStudent() {
        if (count >= 50) {
            cout << "Record full!\n";
            return;
        }
        cout << "\nEnter Student Details:\n";
        s[count].input();
        count++;
        cout << "Student added!\n";
    }

    // Retrieve based on roll number
    void searchStudent(int roll) {
        for (int i = 0; i < count; i++) {
            if (s[i].roll == roll) {
                cout << "\nRecord Found:\n";
                s[i].display();
                return;
            }
        }
        cout << "No student found with Roll Number " << roll << endl;
    }

    // Display all records
    void displayAll() {
        if (count == 0) {
            cout << "No records found.\n";
            return;
        }

        cout << "\nAll Student Records:\n";
        for (int i = 0; i < count; i++) {
            s[i].display();
        }
    }
};

// ---------------- MAIN PROGRAM ----------------
int main() {
    StudentRecords records;
    int choice, roll;

    do {
        cout << "\n--- STUDENT RECORD SYSTEM ---\n";
        cout << "1. Add Student\n2. Search Student by Roll No\n3. Display All\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            records.addStudent();
            break;

        case 2:
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            records.searchStudent(roll);
            break;

        case 3:
            records.displayAll();
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