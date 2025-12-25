/** Write a program to input marks of n students Sort the marks in
ascending order using the Quick Sort algorithm without using
built-in library functions and analyse the sorting algorithm pass
by pass. Find the minimum and maximum marks using Divide and
Conquer (recursively) **/

#include <iostream>
using namespace std;

// ----------- Display Array -----------
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ----------- Partition Function for Quick Sort -----------
int partition(int arr[], int low, int high, int n, int pass) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    cout << "Pass " << pass << ": ";
    display(arr, n);

    return i + 1;
}

// ----------- Quick Sort -----------
void quickSort(int arr[], int low, int high, int n, int &pass) {
    if (low < high) {
        int pi = partition(arr, low, high, n, ++pass);
        quickSort(arr, low, pi - 1, n, pass);
        quickSort(arr, pi + 1, high, n, pass);
    }
}

// ----------- Find Min & Max using Divide and Conquer -----------
void findMinMax(int arr[], int low, int high, int &minVal, int &maxVal) {
    if (low == high) {
        if (arr[low] < minVal) minVal = arr[low];
        if (arr[low] > maxVal) maxVal = arr[low];
    } 
    else if (high == low + 1) {
        if (arr[low] < arr[high]) {
            if (arr[low] < minVal) minVal = arr[low];
            if (arr[high] > maxVal) maxVal = arr[high];
        } else {
            if (arr[high] < minVal) minVal = arr[high];
            if (arr[low] > maxVal) maxVal = arr[low];
        }
    } 
    else {
        int mid = (low + high) / 2;
        findMinMax(arr, low, mid, minVal, maxVal);
        findMinMax(arr, mid + 1, high, minVal, maxVal);
    }
}

// ----------- Main Function -----------
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[50];
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    cout << "\nOriginal Marks: ";
    display(marks, n);

    // Quick Sort with pass-by-pass analysis
    int pass = 0;
    quickSort(marks, 0, n - 1, n, pass);

    cout << "\nSorted Marks (Ascending): ";
    display(marks, n);

    // Find Min and Max using Divide and Conquer
    int minVal = INT_MAX, maxVal = INT_MIN;
    findMinMax(marks, 0, n - 1, minVal, maxVal);

    cout << "\nMinimum Marks: " << minVal;
    cout << "\nMaximum Marks: " << maxVal << endl;

    return 0;
}
