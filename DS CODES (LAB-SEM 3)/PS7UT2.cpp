/** WAP to perform addition o f two polynomials using singly linked list. **/
  
#include <iostream>
using namespace std;

// -------- Node Structure for Polynomial Term --------
struct Node {
    int coef;    // coefficient
    int pow;     // power
    Node* next;
};

// -------- Create a new node --------
Node* createNode(int c, int p) {
    Node* temp = new Node;
    temp->coef = c;
    temp->pow = p;
    temp->next = nullptr;
    return temp;
}

// -------- Insert node at end of list --------
void insert(Node*& head, int c, int p) {
    Node* temp = createNode(c, p);

    if (head == nullptr) {
        head = temp;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = temp;
}

// -------- Display polynomial --------
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->coef << "x^" << temp->pow;
        if (temp->next != nullptr)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

// -------- Add two polynomials --------
Node* addPoly(Node* p1, Node* p2) {
    Node* result = nullptr;

    while (p1 != nullptr && p2 != nullptr) {

        // If powers are equal → add coefficients
        if (p1->pow == p2->pow) {
            insert(result, p1->coef + p2->coef, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        // If p1 has higher power
        else if (p1->pow > p2->pow) {
            insert(result, p1->coef, p1->pow);
            p1 = p1->next;
        }
        // If p2 has higher power
        else {
            insert(result, p2->coef, p2->pow);
            p2 = p2->next;
        }
    }

    // Insert remaining terms of p1
    while (p1 != nullptr) {
        insert(result, p1->coef, p1->pow);
        p1 = p1->next;
    }

    // Insert remaining terms of p2
    while (p2 != nullptr) {
        insert(result, p2->coef, p2->pow);
        p2 = p2->next;
    }

    return result;
}

int main() {

    Node *poly1 = nullptr, *poly2 = nullptr;

    // ------- Polynomial 1 Input -------
    cout << "Enter Polynomial 1 (coeff power). Enter -1 -1 to stop:\n";
    while (true) {
        int c, p;
        cin >> c >> p;
        if (c == -1 && p == -1) break;
        insert(poly1, c, p);
    }

    // ------- Polynomial 2 Input -------
    cout << "Enter Polynomial 2 (coeff power). Enter -1 -1 to stop:\n";
    while (true) {
        int c, p;
        cin >> c >> p;
        if (c == -1 && p == -1) break;
        insert(poly2, c, p);
    }

    // ------- Display Input Polynomials -------
    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    // ------- Add Both Polynomials -------
    Node* sum = addPoly(poly1, poly2);

    // ------- Display Result -------
    cout << "\nResult (Sum): ";
    display(sum);

    return 0;
}
