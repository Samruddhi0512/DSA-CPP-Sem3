/* Write a program to perform Binary Search Tree (BST) operations
(Create, Insert, Delete,Levelwise display )*/

/** 
 *                    UNIT 4   
 */

 #include <iostream>
#include <queue>  // for level-wise display
using namespace std;

// Structure for a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a new node into BST
Node* insertNode(Node* root, int value) {
    // If tree is empty, create the root
    if (root == nullptr)
        return createNode(value);

    // Otherwise, recur down the tree
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Function to find the smallest node (used in delete)
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return root;

    // Traverse the tree
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children:
        Node* temp = findMin(root->right);
        root->data = temp->data; // Copy successor's value
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to display the BST level-wise (Breadth-First Search)
void levelOrder(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "Level-wise display: ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        // Enqueue left and right children
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;
    int choice, value;

    cout << "=== BINARY SEARCH TREE OPERATIONS ===\n";

    do {
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Level-wise Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node inserted.\n";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Node deleted (if present).\n";
                break;

            case 3:
                levelOrder(root);
                break;

            case 4:
                cout << "Exiting program. Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}