/** Develop a program to identify and efficiently store a sparse
matrix using compact representation and perform basic
operations like display and simple transpose.
A sparse matrix is a matrix that has more zero elements than non-zero elements.  **/

#include <iostream>
using namespace std;

int main() {

    int rows, cols, matrix[10][10];

    // Step 1: Input matrix
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Step 2: Count non-zero elements
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0)
                count++;
        }
    }

    // Step 3: Create compact representation (row, col, value)
    int compact[10][3];
    int k = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Display original matrix
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Display compact representation
    cout << "\nCompact Representation (row col value):\n";
    for (int i = 0; i < count; i++) {
        cout << compact[i][0] << "\t"
             << compact[i][1] << "\t"
             << compact[i][2] << endl;
    }

    // Step 4: Simple Transpose of compact matrix
    int transpose[10][3];

    for (int i = 0; i < count; i++) {
        transpose[i][0] = compact[i][1]; // swap row & column
        transpose[i][1] = compact[i][0];
        transpose[i][2] = compact[i][2];
    }

    // Display transpose in compact form
    cout << "\nSimple Transpose (row col value):\n";
    for (int i = 0; i < count; i++) {
        cout << transpose[i][0] << "\t"
             << transpose[i][1] << "\t"
             << transpose[i][2] << endl;
    }

    return 0;
}
