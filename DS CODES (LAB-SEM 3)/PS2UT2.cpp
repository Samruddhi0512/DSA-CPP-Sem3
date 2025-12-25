/** The ticket reservation system for Galaxy Multiplex is to be
implemented using a C++ program. The multiplex has 8 rows,
with 8 seats in each row. A doubly circular linked list will be used
to track the availability of seats in each row.Initially, assume that
some seats are randomly booked. An array will store head
pointers for each row’s linked list.The system should support the
following operations:
a. Display the current list of available seats.
b. Book one or more seats as per customer request.
c. Cancel an existing booking when requested.  **/

#include <iostream>
using namespace std;

struct Seat {
    int seatNo;
    bool booked;         // false = available, true = booked
    Seat* next;
    Seat* prev;
};

class Multiplex {
private:
    Seat* rows[8]; // array of head pointers (1 row = 1 circular linked list)

public:
    Multiplex() {
        // Create 8 rows with 8 seats each
        for (int i = 0; i < 8; i++) {
            rows[i] = NULL;
            createRow(i);
        }
        // Randomly mark some seats as booked initially
        rows[0]->booked = true;
        rows[2]->next->booked = true;
        rows[4]->next->next->booked = true;
    }

    // Create a circular doubly linked list for a row
    void createRow(int rowIndex) {
        Seat* head = NULL;
        Seat* tail = NULL;

        for (int i = 1; i <= 8; i++) {
            Seat* newSeat = new Seat;
            newSeat->seatNo = i;
            newSeat->booked = false;
            newSeat->next = newSeat->prev = NULL;

            if (head == NULL) {
                head = newSeat;
                tail = newSeat;
            } else {
                tail->next = newSeat;
                newSeat->prev = tail;
                tail = newSeat;
            }
        }
        // make it circular
        head->prev = tail;
        tail->next = head;

        rows[rowIndex] = head;
    }

    // Display seat availability
    void displaySeats() {
        cout << "\n--- Galaxy Multiplex Seat Availability ---\n";
        for (int i = 0; i < 8; i++) {
            cout << "Row " << i + 1 << ": ";
            Seat* temp = rows[i];
            do {
                if (temp->booked)
                    cout << "[X] "; // booked seat
                else
                    cout << "[O] "; // available seat
                temp = temp->next;
            } while (temp != rows[i]);
            cout << endl;
        }
    }

    // Book seats
    void bookSeat() {
        int row, seat;
        cout << "Enter Row (1-8): ";
        cin >> row;
        cout << "Enter Seat Number (1-8): ";
        cin >> seat;

        Seat* temp = rows[row - 1];
        for (int i = 1; i < seat; i++) {
            temp = temp->next;
        }

        if (temp->booked) {
            cout << " Seat already booked!\n";
        } else {
            temp->booked = true;
            cout << " Seat booked successfully!\n";
        }
    }

    // Cancel booking
    void cancelSeat() {
        int row, seat;
        cout << "Enter Row (1-8): ";
        cin >> row;
        cout << "Enter Seat Number (1-8): ";
        cin >> seat;

        Seat* temp = rows[row - 1];
        for (int i = 1; i < seat; i++) {
            temp = temp->next;
        }

        if (!temp->booked) {
            cout << " Seat is not booked!\n";
        } else {
            temp->booked = false;
            cout << " Booking cancelled successfully!\n";
        }
    }
};

int main() {
    Multiplex galaxy;
    int choice;

    while (true) {
        cout << "\n--- Galaxy Multiplex Ticket System ---";
        cout << "\n1. Display Available Seats";
        cout << "\n2. Book a Seat";
        cout << "\n3. Cancel Booking";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            galaxy.displaySeats();
            break;
        case 2:
            galaxy.bookSeat();
            break;
        case 3:
            galaxy.cancelSeat();
            break;
        case 0:
            cout << "Thank you! Visit Again.\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}

