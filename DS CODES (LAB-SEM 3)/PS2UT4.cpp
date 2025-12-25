/** Write a program to perform Binary Search Tree (BST) operations
(Count the total number of nodes, Compute the height of the BST,
Mirror Image ). */
/** 
 *                    UNIT 4   
 */

 #include <iostream>
using namespace std;

// Structure for a node in BST
struct Node {
    int data;
    Node *left, *right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to count total nodes in BST
int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to compute height of BST
int height(Node* root) {
    if (root == NULL)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return 1 + max(leftH, rightH);
}

// Function to create mirror image of BST
void mirror(Node* root) {
    if (root == NULL)
        return;
    
    // Swap left and right child
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);
}

// Function for inorder traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    cout << "\n=== BINARY SEARCH TREE OPERATIONS ===\n";

    do {
        cout << "\n1. Insert Node";
        cout << "\n2. Count Total Nodes";
        cout << "\n3. Compute Height";
        cout << "\n4. Mirror Image";
        cout << "\n5. Display Inorder";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Total number of nodes: " << countNodes(root) << endl;
                break;

            case 3:
                cout << "Height of BST: " << height(root) << endl;
                break;

            case 4:
                mirror(root);
                cout << "Mirror image created successfully!\n";
                break;

            case 5:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}