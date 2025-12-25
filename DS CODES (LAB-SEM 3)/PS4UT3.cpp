/**  You are given a string containing only parentheses characters: 
  '(', ')', '{', '}', '[', and ']'. Your task is to check whether the
parentheses are balanced or not. A string is considered balanced if: 
Every opening bracket has a corresponding closing bracket of the same type Brackets are closed in the correct order.**/

#include <iostream>
using namespace std;

// -------- Stack implementation using array --------
class Stack {
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    char peek() {
        return arr[top];
    }
};

// -------- Function to check matching brackets --------
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// -------- Check whether string is balanced --------
bool isBalanced(string s) {
    Stack st;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If opening bracket → push to stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // If closing bracket → stack should not be empty
        else if (c == ')' || c == '}' || c == ']') {

            if (st.isEmpty())
                return false;   // closing without opening

            char top = st.pop();

            if (!isMatching(top, c))
                return false;   // incorrect match
        }
    }

    // If stack empty → all brackets matched
    return st.isEmpty();
}

int main() {
    string input;

    cout << "Enter parentheses string: ";
    cin >> input;

    if (isBalanced(input))
        cout << "Balanced Parentheses\n";
    else
        cout << "Not Balanced\n";

    return 0;
}