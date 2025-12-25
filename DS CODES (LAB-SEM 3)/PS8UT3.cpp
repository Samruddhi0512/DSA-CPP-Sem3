/* Write a program that maintains a queue of passengers waiting to
see a ticket agent. The program user should be able to insert a
new passenger at the rear of the queue, Display the passenger at
the front of the Queue, or remove the passenger at the front of
the queue. The program will display the number of passengers
left in the queue just before it terminates. */

/** 
 *                    UNIT 3  QUEUES
 */

 #include <iostream>
#include <queue>    // for using STL queue
#include <string>   // for using string data type
using namespace std;

int main() {
    queue<string> passengers;   // Queue to store names of passengers
    int choice;                 // To store user's menu choice
    string name;                // To store passenger name

    cout << "=== PASSENGER QUEUE MANAGEMENT SYSTEM ===\n";


    
    do {
        // Display menu options
        cout << "\n1. Add Passenger";
        cout << "\n2. Show Front Passenger";
        cout << "\n3. Serve Passenger";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            // Case 1: Add passenger to the queue
            case 1:
                cout << "Enter passenger name: ";
                cin >> name;
                passengers.push(name);   // Add passenger at rear
                cout << name << " added to the queue.\n";
                break;

            // Case 2: Display the passenger at the front
            case 2:
                if (passengers.empty())  // Check if queue is empty
                    cout << "No passengers waiting.\n";
                else
                    cout << "Front passenger: " << passengers.front() << endl;
                break;

            // Case 3: Serve (remove) the front passenger
            case 3:
                if (passengers.empty())
                    cout << "No passengers to serve.\n";
                else {
                    cout << passengers.front() << " has been served.\n";
                    passengers.pop();   // Remove the front passenger
                }
                break;

            // Case 4: Exit the program
            case 4:
                cout << "\nNumber of passengers left in queue: "
                     << passengers.size() << endl;  // Display remaining passengers
                cout << "Exiting system. Thank you!\n";
                break;

            // Default case: Invalid menu option
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);   // Loop continues until user chooses to exit

    return 0;
}