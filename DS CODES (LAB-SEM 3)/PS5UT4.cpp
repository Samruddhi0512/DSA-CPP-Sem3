/** Write a Program to create a Binary Tree and perform the
following Recursive operations on it. a. Inorder Traversal b.
Preorder Traversal c. Display Number of Leaf Nodes d. Mirror
Image
 */
/** 
 *                    UNIT 4   
 */

 #include <iostream>
using namespace std;

// Class representing a node in the Binary Tree
class Node {
public:
    int data;           // Value stored in the node
    Node *left, *right; // Pointers to left and right children

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Class for Binary Tree
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

    // Function to create a sample tree
    // Example Tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    void createSampleTree() {
        root = createNode(1);
        root->left = createNode(2);
        root->right = createNode(3);
        root->left->left = createNode(4);
        root->left->right = createNode(5);
    }

    // (a) Recursive Inorder Traversal (Left, Root, Right)
    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);          // Visit left subtree
        cout << root->data << " ";    // Print root data
        inorder(root->right);         // Visit right subtree
    }

    // (b) Recursive Preorder Traversal (Root, Left, Right)
    void preorder(Node* root) {
        if (root == NULL)
            return;

        cout << root->data << " ";    // Print root data
        preorder(root->left);         // Visit left subtree
        preorder(root->right);        // Visit right subtree
    }

    // (c) Count number of leaf nodes recursively
    int countLeafNodes(Node* root) {
        if (root == NULL)
            return 0;

        // If node has no children, it is a leaf node
        if (root->left == NULL && root->right == NULL)
            return 1;

        // Recursively count leaf nodes in both subtrees
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }

    // (d) Create Mirror Image of Binary Tree recursively
    void mirror(Node* root) {
        if (root == NULL)
            return;

        // Swap left and right subtrees
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively call for left and right subtrees
        mirror(root->left);
        mirror(root->right);
    }
};

// Main function
int main() {
    BinaryTree tree;
    int choice;

    // Create a sample tree
    tree.createSampleTree();

    cout << "\n=== BINARY TREE RECURSIVE OPERATIONS ===\n";

    do {
        cout << "\n1. Inorder Traversal (Recursive)";
        cout << "\n2. Preorder Traversal (Recursive)";
        cout << "\n3. Display Number of Leaf Nodes";
        cout << "\n4. Mirror Image of Tree";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inorder Traversal: ";
                tree.inorder(tree.root);
                cout << endl;
                break;

            case 2:
                cout << "Preorder Traversal: ";
                tree.preorder(tree.root);
                cout << endl;
                break;

            case 3:
                cout << "Number of Leaf Nodes: " << tree.countLeafNodes(tree.root) << endl;
                break;

            case 4:
                tree.mirror(tree.root);
                cout << "Mirror Image of Tree created successfully!\n";
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