/** Write a program to implement multiple stack i.e more than two stack using array and perform following operations on it.
 *  A. Push B. Pop C. Stack Overflow D. Stack Underflow E. Display */

 #include <iostream>
using namespace std;

class MultipleStack {
    int arr[50];     // main array
    int top[5];      // top pointer for each stack
    int n, size;     // number of stacks, size of array

public:

    // ---- Constructor ----
    MultipleStack(int stacks, int arrSize) {
        n = stacks;
        size = arrSize;

        // Initialize all stack tops to -1
        for (int i = 0; i < n; i++)
            top[i] = -1;
    }

    // ---- Check Overflow ----
    bool isFull() {
        int count = 0;
        for (int i = 0; i < n; i++)
            count += (top[i] + 1);

        return (count == size);  // array is completely full
    }

    // ---- Check Underflow ----
    bool isEmpty(int s) {
        return (top[s] == -1);
    }

    // ---- Push into a stack ----
    void push(int s, int value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }

        top[s]++;              // increase stack’s top
        arr[indexOf(s)] = value;
    }

    // ---- Pop from a stack ----
    int pop(int s) {
        if (isEmpty(s)) {
            cout << "Stack Underflow!\n";
            return -1;
        }

        int value = arr[indexOf(s)];
        top[s]--;  // reduce top pointer
        return value;
    }

    // ---- Calculate actual index for stack s ----
    int indexOf(int s) {
        int index = 0;

        // add sizes of previous stacks
        for (int i = 0; i < s; i++) {
            index += (top[i] + 1);
        }
        // add current stack top
        index += top[s];

        return index;
    }

    // ---- Display a chosen stack ----
    void display(int s) {
        if (isEmpty(s)) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack " << s + 1 << ": ";
        for (int i = 0; i <= top[s]; i++) {
            cout << arr[indexOfElement(s, i)] << " ";
        }
        cout << endl;
    }

    // helper to get element index
    int indexOfElement(int s, int pos) {
        int index = 0;
        for (int i = 0; i < s; i++)
            index += (top[i] + 1);

        return index + pos;
    }
};

int main() {
    int stacks, arrSize;

    cout << "Enter number of stacks: ";
    cin >> stacks;

    cout << "Enter array size: ";
    cin >> arrSize;

    MultipleStack ms(stacks, arrSize);

    int choice, stackNum, value;

    do {
        cout << "\n--- MULTIPLE STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stack number (0 to " << stacks - 1 << "): ";
            cin >> stackNum;
            cout << "Enter value: ";
            cin >> value;
            ms.push(stackNum, value);
            break;

        case 2:
            cout << "Enter stack number (0 to " << stacks - 1 << "): ";
            cin >> stackNum;
            cout << "Popped: " << ms.pop(stackNum) << endl;
            break;

        case 3:
            cout << "Enter stack number (0 to " << stacks - 1 << "): ";
            cin >> stackNum;
            ms.display(stackNum);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}