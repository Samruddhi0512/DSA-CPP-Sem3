/** Write a program to keep track of patients as they checked into a
medical clinic, assigning patients to doctors on a first-come, firstserved basis.
 */
 /** 
 *                    UNIT 3  QUEUES
 */

 #include <iostream>
#include <queue>   // for queue
#include <string>  // for string

using namespace std;

int main() {
    queue<string> patients;   // Queue to store patient names
    int choice;
    string name;

    cout << "=== MEDICAL CLINIC PATIENT MANAGEMENT ===\n";

    do {
        cout << "\n1. Check-in Patient";
        cout << "\n2. Assign Patient to Doctor";
        cout << "\n3. Show Waiting Patients";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                patients.push(name); // Add patient to queue
                cout << name << " has been checked in.\n";
                break;

            case 2:
                if (patients.empty()) {
                    cout << "No patients waiting.\n";
                } else {
                    cout << patients.front() << " is assigned to the doctor.\n";
                    patients.pop(); // Remove the patient from queue
                }
                break;

            case 3:
                if (patients.empty()) {
                    cout << "No patients in waiting list.\n";
                } else {
                    cout << "Patients waiting: ";
                    queue<string> temp = patients; // Copy queue to display
                    while (!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 4:
                cout << "Exiting system. Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}