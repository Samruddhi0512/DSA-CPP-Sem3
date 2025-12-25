/** Write a program using Bubble sort algorithm, assign the roll nos.
to the students of your class as per their previous years result. i.e.
topper will be roll no. 1 and analyse the sorting algorithm pass by
pass. **/

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
    int roll_no;
};

// Function to display student details
void display(Student s[], int n) {
    cout << "\nName\tMarks\tRoll No.\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].name << "\t" << s[i].marks << "\t" << s[i].roll_no << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[50];

    // Input student details
    cout << "\nEnter student details (Name and Marks):\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " Name: ";
        cin >> s[i].name;
        cout << "Marks: ";
        cin >> s[i].marks;
        s[i].roll_no = 0; // initially no roll number assigned
    }

    // Bubble Sort (Descending by marks)
    cout << "\n--- Bubble Sort Pass by Pass ---\n";
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].marks < s[j + 1].marks) { // descending order
                swap(s[j], s[j + 1]);
                swapped = true;
            }
        }

        cout << "After Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << s[k].marks << " ";
        }
        cout << endl;

        if (!swapped) break; // stop if already sorted
    }

    // Assign roll numbers based on rank (sorted order)
    for (int i = 0; i < n; i++) {
        s[i].roll_no = i + 1; // topper gets roll no. 1
    }

    // Display final list
    cout << "\n--- Final Student List (After Sorting & Roll No. Assignment) ---";
    display(s, n);

    return 0;
}

