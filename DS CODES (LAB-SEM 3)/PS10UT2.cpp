/** Given a list, split it into two sublists — one for the front half,
 *  and one for the back half. If the number of elements is odd, 
 * the extra element should go in the front list.
 *  So FrontBackSplit() on the list {2, 3, 5, 7, 11}
 *  should yield the two lists {2, 3, 5} and {7, 11}. 
 * Getting this right for all the cases is harder than it looks.
 *  You should check your solution against a few cases 
 * (length = 2, length = 3, length=4) to make sure that the list gets split correctly 
 * near the shortlist boundary conditions. If it works right for length=4, 
 * it probably works right for length=1000. 
 * You will probably need special case code to deal with the (length <2) cases.  */

 /** 
 *                    UNIT 2
 */

 
 #include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end
void insertEnd(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display a linked list
void displayList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to split a list into front and back halves
void FrontBackSplit(Node* source, Node*& front, Node*& back) {
    // Special cases: list is empty or has only one element
    if (source == NULL) {
        front = NULL;
        back = NULL;
        return;
    }
    if (source->next == NULL) {
        front = source;
        back = NULL;
        return;
    }

    // Use slow and fast pointer approach
    Node* slow = source;
    Node* fast = source->next;

    // Move fast by two nodes, slow by one node
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is at the end of the front half
    front = source;
    back = slow->next;
    slow->next = NULL; // Break the list
}

int main() {
    Node* head = NULL;
    Node* front = NULL;
    Node* back = NULL;
    int n, val;

    cout << "Enter number of elements in the list: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(head, val);
    }

    cout << "\nOriginal List: ";
    displayList(head);

    // Split the list
    FrontBackSplit(head, front, back);

    cout << "Front half: ";
    displayList(front);

    cout << "Back half: ";
    displayList(back);

    return 0;
}
