/* Write a Program to create a Binary Tree and perform following
Nonrecursive operations on it. a. Inorder Traversal b. Preorder
Traversal c. Display Number of Leaf Nodes d. Mirror Image
*/
/** 
 *                    UNIT 4   
 */

 #include <iostream>
#include <stack>   // Used for non-recursive traversals
using namespace std;

// Node class representing each element of the Binary Tree
class Node {
public:
    int data;          // Stores data
    Node *left, *right; // Pointers to left and right child nodes

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// BinaryTree class with all required operations
class BinaryTree {
public:
    Node* root;   // Root node of the tree

    // Constructor initializes root to NULL
    BinaryTree() {
        root = NULL;
    }

    // Function to create a new node
    Node* createNode(int value) {
        return new Node(value);
    }

    // Function to create a simple fixed Binary Tree
    // (You can modify this for manual input)
    void createSampleTree() {
        // Example tree structure:
        //        1
        //       / \
        //      2   3
        //     / \
        //    4   5
        root = createNode(1);
        root->left = createNode(2);
        root->right = createNode(3);
        root->left->left = createNode(4);
        root->left->right = createNode(5);
    }

    // (a) Non-Recursive Inorder Traversal (Left, Root, Right)
    void inorderNonRecursive(Node* root) {
        if (root == NULL) return;

        stack<Node*> s;       // Stack to keep track of nodes
        Node* current = root; // Start from root

        cout << "Inorder Traversal: ";
        while (current != NULL || !s.empty()) {
            // Reach the leftmost node
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }

            // Visit the node on top of stack
            current = s.top();
            s.pop();

            cout << current->data << " ";  // Print data

            // Move to right subtree
            current = current->right;
        }
        cout << endl;
    }

    // (b) Non-Recursive Preorder Traversal (Root, Left, Right)
    void preorderNonRecursive(Node* root) {
        if (root == NULL) return;

        stack<Node*> s;   // Stack to hold nodes
        s.push(root);

        cout << "Preorder Traversal: ";
        while (!s.empty()) {
            Node* current = s.top();
            s.pop();

            cout << current->data << " ";  // Visit node

            // Push right first so left is processed first
            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
        cout << endl;
    }

    // (c) Count number of Leaf Nodes (non-recursive)
    int countLeafNodes(Node* root) {
        if (root == NULL) return 0;

        stack<Node*> s;
        s.push(root);
        int count = 0;

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();

            // Leaf node has no left or right child
            if (current->left == NULL && current->right == NULL)
                count++;

            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
        return count;
    }

    // (d) Create Mirror Image (non-recursive)
    void mirrorNonRecursive(Node* root) {
        if (root == NULL) return;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();

            // Swap left and right child
            Node* temp = current->left;
            current->left = current->right;
            current->right = temp;

            // Push children into stack
            if (current->left)
                s.push(current->left);
            if (current->right)
                s.push(current->right);
        }
        cout << "Mirror Image of the Tree created successfully!\n";
    }
};

// Main function
int main() {
    BinaryTree tree;
    int choice;

    // Create a sample binary tree
    tree.createSampleTree();

    cout << "\n=== BINARY TREE NON-RECURSIVE OPERATIONS ===\n";

    do {
        cout << "\n1. Inorder Traversal (Non-Recursive)";
        cout << "\n2. Preorder Traversal (Non-Recursive)";
        cout << "\n3. Count Leaf Nodes";
        cout << "\n4. Create Mirror Image";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.inorderNonRecursive(tree.root);
                break;

            case 2:
                tree.preorderNonRecursive(tree.root);
                break;

            case 3:
                cout << "Total Leaf Nodes: " << tree.countLeafNodes(tree.root) << endl;
                break;

            case 4:
                tree.mirrorNonRecursive(tree.root);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}