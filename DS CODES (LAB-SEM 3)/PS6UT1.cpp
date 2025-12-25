/**  In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech.
students. Assume that all these students are on ground for a
function. We need to identify a student of S.Y. div. (X) whose
name is "XYZ" and roll no. is "17". Apply appropriate Searching
method to identify the required student.**/

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string year;
    string div;
    string name;
    int roll;
};

int main() {
    int n;
    cout << "Enter total number of students: ";
    cin >> n;

    Student s[50];  // array of students

    // Step 1: Input student details
    cout << "\nEnter details of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << " details:\n";
        cout << "Year (S.Y./T.Y./B.Tech): ";
        cin >> s[i].year;
        cout << "Division: ";
        cin >> s[i].div;
        cout << "Name: ";
        cin >> s[i].name;
        cout << "Roll Number: ";
        cin >> s[i].roll;
    }

    // Step 2: Search for S.Y. div X student "XYZ" roll no 17
    string searchYear = "S.Y.";
    string searchDiv = "X";
    string searchName = "XYZ";
    int searchRoll = 17;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (s[i].year == searchYear && s[i].div == searchDiv &&
            s[i].name == searchName && s[i].roll == searchRoll) {
            cout << "\n Student found!\n";
            cout << "Details:\n";
            cout << "Year: " << s[i].year << "\nDivision: " << s[i].div
                 << "\nName: " << s[i].name << "\nRoll No.: " << s[i].roll << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n Student not found!\n";
    }

    return 0;
}
