/** WAP to implement Bubble sort and Quick Sort on a 1D array of
Student structure (contains student_name, student_roll_no,
total_marks), with key as student_roll_no. And count the number
of swap performed by each method */

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll_no;
    float total_marks;
};

// Function to display student records
void display(Student s[], int n) {
    cout << "\nRoll No\tName\tTotal Marks\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].roll_no << "\t" << s[i].name << "\t" << s[i].total_marks << endl;
    }
}

// ------------------- BUBBLE SORT -------------------
int bubbleSort(Student s[], int n) {
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll_no > s[j + 1].roll_no) {
                swap(s[j], s[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

// ------------------- QUICK SORT -------------------
int quickSortSwapCount = 0;

int partition(Student s[], int low, int high) {
    int pivot = s[high].roll_no;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (s[j].roll_no < pivot) {
            i++;
            swap(s[i], s[j]);
            quickSortSwapCount++;
        }
    }
    swap(s[i + 1], s[high]);
    quickSortSwapCount++;
    return i + 1;
}

void quickSort(Student s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

int main() {
    int n;
    Student s[50], s1[50];

    cout << "Enter number of students: ";
    cin >> n;

    // Input student details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> s[i].name;
        cout << "Roll No: ";
        cin >> s[i].roll_no;
        cout << "Total Marks: ";
        cin >> s[i].total_marks;
    }

    // Copy original data for second sort
    for (int i = 0; i < n; i++) {
        s1[i] = s[i];
    }

    // ---------- Bubble Sort ----------
    int bubbleSwaps = bubbleSort(s, n);
    cout << "\n--- After Bubble Sort (by Roll No) ---";
    display(s, n);
    cout << "Total swaps performed (Bubble Sort): " << bubbleSwaps << endl;

    // ---------- Quick Sort ----------
    quickSort(s1, 0, n - 1);
    cout << "\n--- After Quick Sort (by Roll No) ---";
    display(s1, n);
    cout << "Total swaps performed (Quick Sort): " << quickSortSwapCount << endl;

    return 0;
}
