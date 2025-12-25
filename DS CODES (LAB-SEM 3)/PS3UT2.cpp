/** Develop a C++ program to store and manage an appointment
schedule for a single day. Appointments should be scheduled
randomly using a linked list. The system must define the start
time, end time, and specify the minimum and maximum
duration allowed for each appointment slot.
The program should include the following operations:
a. Display the list of currently available time slots.
b. Book a new appointment within the defined time limits.
c. Cancel an existing appointment after validating its time,
availability, and correctness.
d. Sort the appointment list in order of appointment times.
e. Sort the list based on appointment times using pointer
manipulation (without swapping data values).  **/

#include <iostream>
using namespace std;

struct Appointment {
    int startTime; // in hours (24-hour format)
    int endTime;
    Appointment* next;
};

class Schedule {
private:
    Appointment* head;
    int minDuration, maxDuration;

public:
    Schedule(int minD, int maxD) {
        head = NULL;
        minDuration = minD;
        maxDuration = maxD;
    }

    // Display all appointments
    void displayAppointments() {
        if (head == NULL) {
            cout << "No appointments scheduled.\n";
            return;
        }
        cout << "\n--- Appointment List ---\n";
        Appointment* temp = head;
        while (temp) {
            cout << "From " << temp->startTime << ":00 to " << temp->endTime << ":00\n";
            temp = temp->next;
        }
    }

    // Display available slots between 9 AM - 17 PM
    void displayAvailableSlots() {
        cout << "\n--- Available Time Slots ---\n";
        if (head == NULL) {
            cout << "09:00 to 17:00 available.\n";
            return;
        }
        Appointment* temp = head;
        int start = 9;
        while (temp) {
            if (start < temp->startTime) {
                cout << start << ":00 to " << temp->startTime << ":00\n";
            }
            start = temp->endTime;
            temp = temp->next;
        }
        if (start < 17) {
            cout << start << ":00 to 17:00\n";
        }
    }

    // Book a new appointment
    void bookAppointment(int start, int end) {
        if (start < 9 || end > 17 || start >= end) {
            cout << " Invalid time range!\n";
            return;
        }
        int duration = end - start;
        if (duration < minDuration || duration > maxDuration) {
            cout << " Duration must be between " << minDuration << " and " << maxDuration << " hours.\n";
            return;
        }

        // Check overlap
        Appointment* temp = head;
        while (temp) {
            if (!(end <= temp->startTime || start >= temp->endTime)) {
                cout << " Time slot not available (overlaps with existing appointment).\n";
                return;
            }
            temp = temp->next;
        }

        // Create new appointment
        Appointment* newAppt = new Appointment{start, end, NULL};

        // Insert in sorted order
        if (head == NULL || start < head->startTime) {
            newAppt->next = head;
            head = newAppt;
        } else {
            temp = head;
            while (temp->next && temp->next->startTime < start)
                temp = temp->next;
            newAppt->next = temp->next;
            temp->next = newAppt;
        }

        cout << " Appointment booked successfully!\n";
    }

    // Cancel an appointment
    void cancelAppointment(int start, int end) {
        if (head == NULL) {
            cout << "No appointments to cancel.\n";
            return;
        }

        Appointment* temp = head;
        Appointment* prev = NULL;
        while (temp) {
            if (temp->startTime == start && temp->endTime == end) {
                if (prev == NULL) {
                    head = head->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << " Appointment cancelled.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << " Appointment not found.\n";
    }

    // Sort by swapping data values
    void sortByTimeData() {
        if (head == NULL) return;

        for (Appointment* i = head; i != NULL; i = i->next) {
            for (Appointment* j = i->next; j != NULL; j = j->next) {
                if (i->startTime > j->startTime) {
                    swap(i->startTime, j->startTime);
                    swap(i->endTime, j->endTime);
                }
            }
        }
        cout << " Appointments sorted (by swapping data).\n";
    }

    // Sort by changing pointers (without swapping data)
    void sortByPointer() {
        if (head == NULL || head->next == NULL) return;

        Appointment* sorted = NULL;

        while (head) {
            Appointment* current = head;
            head = head->next;

            if (sorted == NULL || current->startTime < sorted->startTime) {
                current->next = sorted;
                sorted = current;
            } else {
                Appointment* temp = sorted;
                while (temp->next && temp->next->startTime < current->startTime) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }
        head = sorted;
        cout << " Appointments sorted (by pointer manipulation).\n";
    }
};

int main() {
    Schedule s(1, 3); // minimum 1 hour, maximum 3 hours per appointment
    int choice, start, end;

    while (true) {
        cout << "\n--- Appointment Scheduler Menu ---\n";
        cout << "1. Display Appointments\n";
        cout << "2. Display Available Slots\n";
        cout << "3. Book Appointment\n";
        cout << "4. Cancel Appointment\n";
        cout << "5. Sort by Time (Swap Data)\n";
        cout << "6. Sort by Time (Pointer Manipulation)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.displayAppointments();
            break;
        case 2:
            s.displayAvailableSlots();
            break;
        case 3:
            cout << "Enter start and end time (24-hr format): ";
            cin >> start >> end;
            s.bookAppointment(start, end);
            break;
        case 4:
            cout << "Enter start and end time to cancel: ";
            cin >> start >> end;
            s.cancelAppointment(start, end);
            break;
        case 5:
            s.sortByTimeData();
            break;
        case 6:
            s.sortByPointer();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
