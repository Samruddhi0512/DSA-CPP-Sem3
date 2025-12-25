/** Write a C++ program to implement a Set using a Generalized Linked List (GLL).     For example:

 Let S = { p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1} }

Store this structure using a Generalized Linked List and display the elements in correct set notation format.
 */

#include <iostream>
#include <string>
using namespace std;

// ----------- Structure for GLL Node -----------
struct GLL {
    string data;   // stores the atom (ex: p, q, r, s)
    GLL *down;     // points to sublist
    GLL *next;     // points to next element
};

// ----------- Create a new node -----------
GLL* createNode(string value, bool isSublist = false) {
    GLL* temp = new GLL;
    temp->data = isSublist ? "" : value; // sublist has empty data
    temp->down = nullptr;
    temp->next = nullptr;
    return temp;
}

// ----------- Display GLL in set format -----------
void display(GLL* head) {
    cout << "{ ";
    GLL* temp = head;

    while (temp != nullptr) {

        // If element is a sublist
        if (temp->down != nullptr) {
            display(temp->down);  // print inside sublist
        }
        else {
            cout << temp->data;  // print the atom
        }

        if (temp->next != nullptr)
            cout << ", ";

        temp = temp->next;
    }

    cout << " }";
}

int main() {

    // ----------- Creating the example GLL manually -----------

    // S = { p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1} }

    // Level 0 list
    GLL *p = createNode("p");
    GLL *q = createNode("q");
    GLL *sub = createNode("", true);

    p->next = q;
    q->next = sub;

    // Level 1 sublist
    GLL *r = createNode("r");
    GLL *s = createNode("s");
    GLL *t = createNode("t");
    GLL *emptySet = createNode("", true);
    GLL *subUV = createNode("", true);
    GLL *w = createNode("w");
    GLL *x = createNode("x");
    GLL *subYZ = createNode("", true);
    GLL *a1 = createNode("a1");
    GLL *b1 = createNode("b1");

    sub->down = r;
    r->next = s;
    s->next = t;
    t->next = emptySet;
    emptySet->next = subUV;
    subUV->next = w;
    w->next = x;
    x->next = subYZ;
    subYZ->next = a1;
    a1->next = b1;

    // Level 2: {u, v}
    GLL *u = createNode("u");
    GLL *v = createNode("v");
    subUV->down = u;
    u->next = v;

    // Level 2: {y, z}
    GLL *y = createNode("y");
    GLL *z = createNode("z");
    subYZ->down = y;
    y->next = z;

    // ----------- Display the Set -----------
    cout << "Generalized Linked List (Set Format):\n";
    display(p);
    cout << endl;

    return 0;
}