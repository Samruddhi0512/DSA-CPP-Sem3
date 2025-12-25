/** Develop a program to compute the fast transpose of a sparse
matrix using its compact (triplet) representation efficiently **/

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

    // Step 2: Store compact representation
    int compact[50][3];
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compact[count][0] = i;   // row
                compact[count][1] = j;   // column
                compact[count][2] = matrix[i][j]; // value
                count++;
            }
        }
    }

    cout << "\nCompact Representation (Row Col Value):\n";
    for (int i = 0; i < count; i++) {
        cout << compact[i][0] << "\t" << compact[i][1] << "\t" << compact[i][2] << endl;
    }

    // Step 3: Fast Transpose
    int colCount[50] = {0};
    int startPos[50] = {0};
    int transpose[50][3];

    // Count number of elements in each column
    for (int i = 0; i < count; i++) {
        colCount[compact[i][1]]++;
    }

    // Calculate starting position of each column in transpose
    startPos[0] = 0;
    for (int i = 1; i < cols; i++) {
        startPos[i] = startPos[i - 1] + colCount[i - 1];
    }

    // Place elements directly in correct position
    for (int i = 0; i < count; i++) {
        int col = compact[i][1];
        int pos = startPos[col];
        transpose[pos][0] = compact[i][1]; // new row
        transpose[pos][1] = compact[i][0]; // new column
        transpose[pos][2] = compact[i][2]; // value
        startPos[col]++;
    }

    // Step 4: Display result
    cout << "\nFast Transpose (Row Col Value):\n";
    for (int i = 0; i < count; i++) {
        cout << transpose[i][0] << "\t" << transpose[i][1] << "\t" << transpose[i][2] << endl;
    }

    return 0;
}
