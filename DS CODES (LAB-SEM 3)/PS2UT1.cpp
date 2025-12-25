/**Write a program to construct and verify a magic square of order
'n' (for both even & odd) such that all rows, columns, and
diagonals sum to the same value. 
   A magic square is a square matrix where:
                         All rows, columns, and diagonals add up to the same sum    **/

 #include <iostream>
using namespace std;

// Function to display the magic square
void display(int square[50][50], int n) {
    cout << "\nMagic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to verify magic square
void verify(int square[50][50], int n) {
    int magicSum = n * (n * n + 1) / 2;
    bool isMagic = true;

    // Check rows
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) rowSum += square[i][j];
        if (rowSum != magicSum) isMagic = false;
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) colSum += square[i][j];
        if (colSum != magicSum) isMagic = false;
    }

    // Check diagonals
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        d1 += square[i][i];
        d2 += square[i][n - i - 1];
    }
    if (d1 != magicSum || d2 != magicSum) isMagic = false;

    cout << "\nVerification: ";
    if (isMagic)
        cout << " It is a magic square.\n";
    else
        cout << " It is NOT a magic square.\n";
}

// Function to construct magic square
void generateMagicSquare(int square[50][50], int n) {
    // Initialize all cells to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = 0;

    if (n % 2 == 1) {
        // ----- For odd n (Siamese method) -----
        int num = 1;
        int i = 0, j = n / 2;

        while (num <= n * n) {
            square[i][j] = num++;
            i--; j++;

            if (num % n == 1) {
                i += 2;
                j--;
            }
            if (i < 0) i = n - 1;
            if (j == n) j = 0;
        }

    } else if (n % 4 == 0) {
        // ----- For doubly even (like 4, 8, 12) -----
        int num = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                square[i][j] = num++;
            }
        }

        // Invert certain cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i % 4 == j % 4) || ((i + j) % 4 == 3))
                    square[i][j] = n * n + 1 - square[i][j];
            }
        }
    } else {
        cout << "Magic square generation for singly even (like 6, 10) is complex.\n";
        cout << "Try odd or doubly even n.\n";
    }
}

int main() {
    int n;
    int square[50][50];

    cout << "Enter order of magic square (n): ";
    cin >> n;

    generateMagicSquare(square, n);
    display(square, n);
    verify(square, n);

    return 0;
}
