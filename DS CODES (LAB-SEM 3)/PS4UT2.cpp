/** In the Second Year Computer Engineering class, there are two
groups of students based on their favorite sports:
● Set A includes students who like Cricket.
● Set B includes students who like Football.
Write a C++ program to represent these two sets using linked
lists and perform the following operations:
a. Find and display the set of students who like both Cricket and
Football.
b. Find and display the set of students who like either Cricket or
Football, but not both.
c. Display the number of students who like neither Cricket nor
Football.   **/

#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
};

class Set {
public:
    Node* head;

    Set() { head = NULL; }

    // Insert a student into the set
    void insert(string name) {
        Node* newNode = new Node{name, NULL};
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display all students
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "Set is empty.\n";
            return;
        }
        while (temp) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Check if a student is present
    bool contains(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->name == name)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

// a) Students who like both sports
Set intersection(Set A, Set B) {
    Set result;
    Node* temp = A.head;
    while (temp) {
        if (B.contains(temp->name))
            result.insert(temp->name);
        temp = temp->next;
    }
    return result;
}

// b) Students who like either but not both (Symmetric difference)
Set symmetricDifference(Set A, Set B) {
    Set result;
    Node* temp = A.head;
    while (temp) {
        if (!B.contains(temp->name))
            result.insert(temp->name);
        temp = temp->next;
    }
    temp = B.head;
    while (temp) {
        if (!A.contains(temp->name))
            result.insert(temp->name);
        temp = temp->next;
    }
    return result;
}

// c) Students who like neither
Set neither(Set total, Set A, Set B) {
    Set result;
    Node* temp = total.head;
    while (temp) {
        if (!A.contains(temp->name) && !B.contains(temp->name))
            result.insert(temp->name);
        temp = temp->next;
    }
    return result;
}

int main() {
    Set total, cricket, football;

    int n;
    cout << "Enter total number of students: ";
    cin >> n;

    cout << "Enter names of all students:\n";
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        total.insert(name);
    }

    int c;
    cout << "\nEnter number of students who like Cricket: ";
    cin >> c;
    cout << "Enter names:\n";
    for (int i = 0; i < c; i++) {
        string name;
        cin >> name;
        cricket.insert(name);
    }

    int f;
    cout << "\nEnter number of students who like Football: ";
    cin >> f;
    cout << "Enter names:\n";
    for (int i = 0; i < f; i++) {
        string name;
        cin >> name;
        football.insert(name);
    }

    cout << "\nSet A (Cricket): ";
    cricket.display();
    cout << "Set B (Football): ";
    football.display();

    // a) Both sports
    cout << "\nStudents who like BOTH Cricket and Football: ";
    Set both = intersection(cricket, football);
    both.display();

    // b) Either but not both
    cout << "Students who like EITHER Cricket OR Football but NOT BOTH: ";
    Set either = symmetricDifference(cricket, football);
    either.display();

    // c) Neither
    cout << "Students who like NEITHER Cricket NOR Football: ";
    Set none = neither(total, cricket, football);
    none.display();

    return 0;
}

