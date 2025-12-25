/** Write a program to implement a product inventory management system for a shop using a search tree data structure. Each product must store the following information:

●      Unique Product Code
●      Product Name
●      Price
●      Quantity in Stock
●    Date Received
●      Expiration Date
Implement the following operations:
Insert a product into the tree (organized by product name).
Display all items in the inventory using inorder traversal.
List expired items in prefix (preorder) order of their names.*/
/** 
 *                    UNIT 4   
 */

#include <iostream>
using namespace std;

// ----------- Product Node -----------
struct Product {
    string code;
    string name;
    float price;
    int quantity;
    string receivedDate;
    string expiryDate;

    Product *left, *right;
};

// ----------- Create a new BST node -----------
Product* createNode(string code, string name, float price, int qty,
                    string recv, string exp) 
{
    Product* p = new Product;
    p->code = code;
    p->name = name;
    p->price = price;
    p->quantity = qty;
    p->receivedDate = recv;
    p->expiryDate = exp;
    p->left = p->right = NULL;
    return p;
}

// ----------- Insert Product (by product name) -----------
Product* insert(Product* root, string code, string name, float price,
                int qty, string recv, string exp) 
{
    if (root == NULL)
        return createNode(code, name, price, qty, recv, exp);

    if (name < root->name)
        root->left = insert(root->left, code, name, price, qty, recv, exp);
    else
        root->right = insert(root->right, code, name, price, qty, recv, exp);

    return root;
}

// ----------- Inorder Traversal (sorted) -----------
void inorder(Product* root) {
    if (root == NULL) return;

    inorder(root->left);

    cout << "\nProduct Name: " << root->name;
    cout << "\nCode: " << root->code;
    cout << "\nPrice: " << root->price;
    cout << "\nQuantity: " << root->quantity;
    cout << "\nReceived: " << root->receivedDate;
    cout << "\nExpiry: " << root->expiryDate;
    cout << "\n------------------------\n";

    inorder(root->right);
}

// ----------- Preorder Traversal (used for expired list) -----------
void listExpired(Product* root, string today) {
    if (root == NULL) return;

    // Check if expired
    if (root->expiryDate < today) {
        cout << root->name << " (Expired on: " << root->expiryDate << ")\n";
    }

    listExpired(root->left, today);
    listExpired(root->right, today);
}

// ---------------- Main Program ----------------
int main() {

    Product* root = NULL;

    int choice, qty;
    float price;
    string code, name, recv, exp, today;

    cout << "Enter today's date (YYYY-MM-DD): ";
    cin >> today;

    while (true) {
        cout << "\n--- PRODUCT INVENTORY SYSTEM (BST) ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. List Expired Products (Preorder)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Product Code: ";
            cin >> code;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Date Received (YYYY-MM-DD): ";
            cin >> recv;
            cout << "Enter Expiry Date (YYYY-MM-DD): ";
            cin >> exp;

            root = insert(root, code, name, price, qty, recv, exp);
            cout << "Product Added!\n";
            break;

        case 2:
            cout << "\n--- INVENTORY LIST (SORTED BY NAME) ---\n";
            inorder(root);
            break;

        case 3:
            cout << "\n--- EXPIRED PRODUCTS (Preorder) ---\n";
            listExpired(root, today);
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}