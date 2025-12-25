/**Implement basic string operations such as length calculation,
copy, reverse, and concatenation using character single
dimensional arrays without using built-in string library functions. **/

#include <iostream>
using namespace std;

int main() {

    char str1[100], str2[100], copyStr[100], revStr[100], concatStr[200];
    int length = 0, i, j;

    // -------- Input first string --------
    cout << "Enter first string: ";
    cin >> str1;

    // -------- 1. Length Calculation --------
    while (str1[length] != '\0') {
        length++;
    }
    cout << "Length of string: " << length << endl;

    // -------- 2. Copy String --------
    for (i = 0; str1[i] != '\0'; i++) {
        copyStr[i] = str1[i];
    }
    copyStr[i] = '\0';   // Add NULL terminator
    cout << "Copied string: " << copyStr << endl;

    // -------- 3. Reverse String --------
    int end = length - 1;
    for (i = 0; i < length; i++) {
        revStr[i] = str1[end - i];
    }
    revStr[i] = '\0';
    cout << "Reversed string: " << revStr << endl;

    // -------- 4. Concatenation --------
    cout << "Enter second string: ";
    cin >> str2;

    // Copy str1 into concatStr
    for (i = 0; str1[i] != '\0'; i++) {
        concatStr[i] = str1[i];
    }

    // Append str2
    for (j = 0; str2[j] != '\0'; j++) {
        concatStr[i + j] = str2[j];
    }
    concatStr[i + j] = '\0';

    cout << "Concatenated string: " << concatStr << endl;

    return 0;
}