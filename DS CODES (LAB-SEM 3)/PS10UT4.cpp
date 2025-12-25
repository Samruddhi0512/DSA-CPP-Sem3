/** Write a program to implement deletion operations in the
product inventory system using a search tree.
Each product must store the following information:
● Unique Product Code
● Product Name
● Price
● Quantity in Stock
● Date Received
● Expiration Date
Implement the following operations:
1. Delete a product using its unique product code.
2. Delete all expired products based on the current date **/
/** 
 *                    UNIT 4   
 */

 #include <iostream>
using namespace std;

// ---------------------------- Product Node ------------------------------
struct Product {
    int code;                 // unique product code (BST key)
    string name;
    float price;
    int quantity;
    string received;
    string expiry;

    Product* left;
    Product* right;
};

// ---------------------------- Create Node -------------------------------
Product* createNode(int code, string name, float price, int qty,
                    string rec, string exp) {
    Product* temp = new Product();
    temp->code = code;
    temp->name = name;
    temp->price = price;
    temp->quantity = qty;
    temp->received = rec;
    temp->expiry = exp;
    temp->left = temp->right = NULL;
    return temp;
}

// ---------------------------- Insert (BST by Code) ----------------------
Product* insert(Product* root, int code, string name, float price,
                int qty, string rec, string exp) {

    if (root == NULL)
        return createNode(code, name, price, qty, rec, exp);

    if (code < root->code)
        root->left = insert(root->left, code, name, price, qty, rec, exp);
    else
        root->right = insert(root->right, code, name, price, qty, rec, exp);

    return root;
}

// ---------------------------- Find Minimum Node -------------------------
Product* findMin(Product* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// ---------------------------- Delete Product by Code --------------------
Product* deleteByCode(Product* root, int code) {

    if (root == NULL)
        return root;

    if (code < root->code)
        root->left = deleteByCode(root->left, code);
    else if (code > root->code)
        root->right = deleteByCode(root->right, code);
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            Product* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Product* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children → use inorder successor
        Product* temp = findMin(root->right);
        root->code = temp->code;
        root->name = temp->name;
        root->price = temp->price;
        root->quantity = temp->quantity;
        root->received = temp->received;
        root->expiry = temp->expiry;

        root->right = deleteByCode(root->right, temp->code);
    }

    return root;
}

// ---------------------------- Check if expired --------------------------
// Simplified: considers expired if year < 2025
bool isExpired(string expiry) {
    int year = stoi(expiry.substr(6, 4));
    return (year < 2025);
}

// ---------------------------- Delete All Expired ------------------------
Product* deleteExpired(Product* root) {
    if (root == NULL)
        return NULL;

    // Process left & right first
    root->left = deleteExpired(root->left);
    root->right = deleteExpired(root->right);

    // If this node is expired → delete it
    if (isExpired(root->expiry)) {
        cout << "Deleting expired product: " << root->name << endl;
        return deleteByCode(root, root->code);
    }

    return root;
}

// ---------------------------- Display Inorder ---------------------------
void inorder(Product* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << "\nCode: " << root->code
         << "\nName: " << root->name
         << "\nPrice: " << root->price
         << "\nQuantity: " << root->quantity
         << "\nReceived: " << root->received
         << "\nExpiry: " << root->expiry
         << "\n-------------------------------";
    inorder(root->right);
}

// ---------------------------- MAIN PROGRAM ------------------------------
int main() {

    Product* root = NULL;
    int choice, code, qty;
    float price;
    string name, rec, exp;

    while (true) {
        cout << "\n\n--- PRODUCT INVENTORY (BST – DELETION) ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Delete Product by Code\n";
        cout << "3. Delete ALL Expired Products\n";
        cout << "4. Display Inventory (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter Code: ";
                cin >> code;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> qty;
                cout << "Date Received (DD/MM/YYYY): ";
                cin >> rec;
                cout << "Expiration Date (DD/MM/YYYY): ";
                cin >> exp;

                root = insert(root, code, name, price, qty, rec, exp);
                break;

            case 2:
                cout << "Enter Code to Delete: ";
                cin >> code;
                root = deleteByCode(root, code);
                cout << "Deleted (if existed)!\n";
                break;

            case 3:
                cout << "Deleting all expired items...\n";
                root = deleteExpired(root);
                cout << "Expired products removed.\n";
                break;

            case 4:
                cout << "\n--- INVENTORY LIST (SORTED BY CODE) ---\n";
                inorder(root);
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!";
        }
    }
}