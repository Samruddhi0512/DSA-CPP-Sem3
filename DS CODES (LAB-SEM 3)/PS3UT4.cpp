/** Write a Program to create a Binary Tree Search and Find
Minimum/Maximum in BST  */
/** 
 *                    UNIT 4   
 */

 #include <iostream>
using namespace std;

// Class representing a single node in BST
class Node {
public:
    int data;
    Node *left, *right;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Class for Binary Search Tree
class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Function to insert a new node in BST
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);

        return root;
    }

    // Function to find minimum value in BST
    int findMin(Node* root) {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        while (root->left != NULL)
            root = root->left;
        return root->data;
    }

    // Function to find maximum value in BST
    int findMax(Node* root) {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        while (root->right != NULL)
            root = root->right;
        return root->data;
    }

    // Function for inorder traversal (Left, Root, Right)
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main() {
    BST tree;
    int choice, value;

    cout << "\n=== BINARY SEARCH TREE OPERATIONS (OOP) ===\n";

    do {
        cout << "\n1. Insert Node";
        cout << "\n2. Display Inorder";
        cout << "\n3. Find Minimum";
        cout << "\n4. Find Maximum";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.root = tree.insert(tree.root, value);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder(tree.root);
                cout << endl;
                break;

            case 3:
                cout << "Minimum value in BST: " << tree.findMin(tree.root) << endl;
                break;

            case 4:
                cout << "Maximum value in BST: " << tree.findMax(tree.root) << endl;
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}