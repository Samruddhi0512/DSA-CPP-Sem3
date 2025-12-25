/** Write a program, using trees, to assign the roll nos. to the
students of your class as per their previous years result. i.e topper
will be roll no. 1
 */
/** 
 *                    UNIT 4   
 */

 #include <iostream>
using namespace std;

// ------------------------ Structure for Tree Node -------------------------
struct Student {
    int marks;            // previous year marks
    string name;          // student name
    Student* left;        // left child (students with LOWER marks)
    Student* right;       // right child (students with HIGHER marks)
};

// ------------------------ Function to Create New Node ---------------------
Student* newNode(int marks, string name) {
    Student* temp = new Student();
    temp->marks = marks;
    temp->name = name;
    temp->left = temp->right = NULL;
    return temp;
}

// ------------------------ Insert Function (BST) ---------------------------
Student* insert(Student* root, int marks, string name) {
    // if root is empty, create new node
    if (root == NULL)
        return newNode(marks, name);

    // students with higher marks go RIGHT
    if (marks > root->marks)
        root->right = insert(root->right, marks, name);

    // students with lower marks go LEFT
    else
        root->left = insert(root->left, marks, name);

    return root;
}

// ------------------------ Inorder Traversal (Descending) ------------------
// We print RIGHT → ROOT → LEFT so highest marks come first.
void assignRollNumbers(Student* root, int &rollNo) {
    if (root == NULL)
        return;

    // Visit higher marks first
    assignRollNumbers(root->right, rollNo);

    // Assign roll number
    cout << "Roll No. " << rollNo << " : " << root->name 
         << " (Marks: " << root->marks << ")" << endl;
    rollNo++;

    // Visit lower marks next
    assignRollNumbers(root->left, rollNo);
}

// ------------------------------ Main Function -----------------------------
int main() {
    Student* root = NULL;

    // Insert students (name, marks)
    root = insert(root, 89, "Samruddhi");
    root = insert(root, 95, "Prayag");
    root = insert(root, 76, "Aditi");
    root = insert(root, 82, "Rohan");
    root = insert(root, 98, "Sarthak");

    cout << "---- Roll Number Assignment Based on Marks ----\n";
    int roll = 1;
    assignRollNumbers(root, roll);

    return 0;
}