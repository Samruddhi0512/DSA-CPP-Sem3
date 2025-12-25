/** Implementation of Singly Linked List to Manage ‘Vertex Club’
Membership Records.
The Department of Computer Engineering has a student club
named ‘Vertex Club’ for second, third, and final year students.
The first member is the President and the last member is the
Secretary. Write a C++ program to:
● Add/delete members (including President/Secretary)
● Count members
● Display members
● Concatenate two division lists
Also implement: reverse, search by PRN, and sort by
PRN operations.   **/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int PRN;
    string name;
    Node* next;
};

class VertexClub {
private:
    Node* head;

public:
    VertexClub() {
        head = NULL;
    }

    // Add President
    void addPresident(int PRN, string name) {
        Node* newNode = new Node{PRN, name, NULL};
        newNode->next = head;
        head = newNode;
        cout << "President added successfully.\n";
    }

    // Add Secretary
    void addSecretary(int PRN, string name) {
        Node* newNode = new Node{PRN, name, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        cout << "Secretary added successfully.\n";
    }

    // Add Member (in the middle)
    void addMember(int PRN, string name) {
        Node* newNode = new Node{PRN, name, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        cout << "Member added successfully.\n";
    }

    // Delete member by PRN
    void deleteMember(int PRN) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        if (head->PRN == PRN) { // delete president
            head = head->next;
            delete temp;
            cout << "President deleted.\n";
            return;
        }

        while (temp != NULL && temp->PRN != PRN) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Member not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Member deleted successfully.\n";
    }

    // Display members
    void display() {
        if (head == NULL) {
            cout << "No members in the club.\n";
            return;
        }
        Node* temp = head;
        cout << "\n--- Vertex Club Members ---\n";
        while (temp != NULL) {
            cout << "PRN: " << temp->PRN << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Count members
    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Search by PRN
    void searchByPRN(int PRN) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->PRN == PRN) {
                cout << "Member found: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found.\n";
    }

    // Reverse the list
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed successfully.\n";
    }

    // Sort list by PRN (Ascending)
    void sortByPRN() {
        if (head == NULL) return;

        for (Node* i = head; i != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->PRN > j->PRN) {
                    swap(i->PRN, j->PRN);
                    swap(i->name, j->name);
                }
            }
        }
        cout << "List sorted by PRN.\n";
    }

    // Concatenate two division lists
    void concatenate(VertexClub& second) {
        if (head == NULL) {
            head = second.head;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = second.head;
        second.head = NULL;
        cout << "Lists concatenated successfully.\n";
    }
};

int main() {
    VertexClub divA, divB;

    // Menu-driven program
    int choice, prn;
    string name;

    while (true) {
        cout << "\n---- Vertex Club Menu ----";
        cout << "\n1. Add President\n2. Add Secretary\n3. Add Member\n4. Delete Member";
        cout << "\n5. Display Members\n6. Count Members\n7. Search by PRN\n8. Reverse List";
        cout << "\n9. Sort by PRN\n10. Concatenate Two Lists\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN and Name: ";
            cin >> prn >> name;
            divA.addPresident(prn, name);
            break;
        case 2:
            cout << "Enter PRN and Name: ";
            cin >> prn >> name;
            divA.addSecretary(prn, name);
            break;
        case 3:
            cout << "Enter PRN and Name: ";
            cin >> prn >> name;
            divA.addMember(prn, name);
            break;
        case 4:
            cout << "Enter PRN to delete: ";
            cin >> prn;
            divA.deleteMember(prn);
            break;
        case 5:
            divA.display();
            break;
        case 6:
            cout << "Total Members: " << divA.countMembers() << endl;
            break;
        case 7:
            cout << "Enter PRN to search: ";
            cin >> prn;
            divA.searchByPRN(prn);
            break;
        case 8:
            divA.reverse();
            break;
        case 9:
            divA.sortByPRN();
            break;
        case 10:
            cout << "\nEnter members for Division B (2 members):\n";
            for (int i = 0; i < 2; i++) {
                cout << "Enter PRN and Name: ";
                cin >> prn >> name;
                divB.addMember(prn, name);
            }
            divA.concatenate(divB);
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
