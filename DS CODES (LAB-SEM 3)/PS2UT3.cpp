/**	Convert given infix expression Eg. a-b*c-d/e+f into postfix 
 * form using stack and show the operations step by step. 	  */

 /** 
 *                    UNIT 3  STACK
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>   // for isalnum
using namespace std;

// Return true if c is an operator we care about
bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

// Precedence: higher value -> higher precedence
int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

// '^' is right-associative; others (+ - * /) are left-associative
bool isLeftAssociative(char op) {
    if (op == '^') return false;
    return true;
}

// Helper to print stack contents from bottom -> top
void printStack(const stack<char>& s) {
    if (s.empty()) {
        cout << "[]";
        return;
    }
    stack<char> tmp = s;               // copy
    vector<char> elems;
    while (!tmp.empty()) {
        elems.push_back(tmp.top());    // elems = top...bottom
        tmp.pop();
    }
    cout << "[";
    for (int i = (int)elems.size()-1; i >= 0; --i) { // print bottom->top
        cout << elems[i];
        if (i > 0) cout << " ";
    }
    cout << "]";
}

// Core: convert and print step-by-step
string infixToPostfixShowSteps(const string& expr) {
    stack<char> st;       // operator stack
    string output = "";   // postfix output

    cout << "Infix : " << expr << "\n";
    cout << "Step-by-step conversion:\n\n";

    for (size_t i = 0; i < expr.size(); ++i) {
        char token = expr[i];
        if (token == ' ' || token == '\t') continue; // skip spaces

        cout << "Read: '" << token << "'\n";

        // If operand (letter or digit) -> append to output
        if (isalnum((unsigned char)token)) {
            output.push_back(token);
            cout << " -> Operand: append to output.\n";
        }
        // If left parenthesis -> push
        else if (token == '(') {
            st.push(token);
            cout << " -> Push '('.\n";
        }
        // If right parenthesis -> pop until '('
        else if (token == ')') {
            cout << " -> Right parenthesis: pop until '('.\n";
            while (!st.empty() && st.top() != '(') {
                output.push_back(st.top());
                cout << "    Pop '" << st.top() << "' to output.\n";
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
                cout << "    Pop '(' and discard.\n";
            } else {
                cout << "    Warning: mismatched parentheses (no matching '(')\n";
            }
        }
        // If operator
        else if (isOperator(token)) {
            cout << " -> Operator '" << token << "' encountered.\n";
            // While conditions (see infix->postfix algorithm w/ associativity)
            while (!st.empty() && st.top() != '(' &&
                   ( precedence(st.top()) > precedence(token) ||
                    ( precedence(st.top()) == precedence(token) && isLeftAssociative(token) )
                   )) {
                cout << "    Top '" << st.top() << "' has higher/equal precedence -> pop to output.\n";
                output.push_back(st.top());
                st.pop();
            }
            st.push(token);
            cout << "    Push '" << token << "' onto stack.\n";
        }
        else {
            cout << " -> Ignored character (not operand/operator/parenthesis).\n";
        }

        // Show current output and stack
        cout << "Output: " << output << "\t Stack: ";
        printStack(st);
        cout << "\n\n";
    }

    // End of input: pop all remaining operators
    cout << "End of expression: pop remaining operators from stack to output.\n";
    while (!st.empty()) {
        if (st.top() == '(' || st.top() == ')') {
            cout << "    Warning: found unmatched parenthesis '" << st.top() << "' - discarding.\n";
            st.pop();
            continue;
        }
        cout << "    Pop '" << st.top() << "' to output.\n";
        output.push_back(st.top());
        st.pop();
    }

    cout << "\nFinal Postfix: " << output << "\n\n";
    return output;
}

int main() {
    // Example demonstration (the example you gave)
    string example = "a-b*c-d/e+f";
    infixToPostfixShowSteps(example);

    // Optional: let user try their own expression
    cout << "Enter your own infix expression (or blank to exit):\n";
    string expr;
    // read full line
    getline(cin, expr); // consume leftover newline
    while (true) {
        cout << "> ";
        if (!getline(cin, expr)) break;
        if (expr.empty()) break;
        infixToPostfixShowSteps(expr);
    }

    cout << "Done.\n";
    return 0;
}


