/** Write a program to implement a product inventory management
system for a shop using a search tree data structure. Each product
must store the following information:
● Unique Product Code
● Product Name
● Price
● Quantity in Stock
● Date Received
● Expiration Date
Implement the following operations:
1. Insert a product into the tree ( organized by product
name).
2. Display all items in the inventory using inorder traversal.
3. List expired items in prefix (preorder) order of their
names. **/
/** 
 *                    UNIT 4   
 */

 #include <iostream>
using namespace std;

// ---------------------------- Product Node ------------------------------
struct Product {
    string code;
    string name;
    float price;
    int quantity;
    string date_received;
    string expiration_date;

    Product* left;
    Product* right;
};

// ---------------------------- Create New Node ---------------------------
Product* createNode(string code, string name, float price, int quantity,
                    string dr, string exp) {

    Product* temp = new Product();
    temp->code = code;
    temp->name = name;
    temp->price = price;
    temp->quantity = quantity;
    temp->date_received = dr;
    temp->expiration_date = exp;

    temp->left = temp->right = NULL;
    return temp;
}

// ---------------------------- Insert by Product Name --------------------
Product* insert(Product* root, string code, string name, float price,
                int quantity, string dr, string exp) {

    if (root == NULL)
        return createNode(code, name, price, quantity, dr, exp);

    // Smaller name → left subtree
    if (name < root->name)
        root->left = insert(root->left, code, name, price, quantity, dr, exp);

    // Larger name → right subtree
    else
        root->right = insert(root->right, code, name, price, quantity, dr, exp);

    return root;
}

// ---------------------------- Inorder Traversal (Sorted by Name) --------
void inorder(Product* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << "\nProduct Name: " << root->name
         << "\nCode: " << root->code
         << "\nPrice: " << root->price
         << "\nQuantity: " << root->quantity
         << "\nDate Received: " << root->date_received
         << "\nExpiration Date: " << root->expiration_date
         << "\n------------------------------";
    inorder(root->right);
}

// ---------------------------- Check If Expired --------------------------
bool isExpired(string exp_date) {
    // *** SIMPLE CHECK ***
    // Format expected: DD/MM/YYYY
    // Expired if year < 2025 (you can modify as needed)
    int year = stoi(exp_date.substr(6, 4));
    return (year < 2025);
}

// ---------------------------- Preorder Display of Expired Items ---------
void listExpired(Product* root) {
    if (root == NULL) return;

    // Visit node first (preorder)
    if (isExpired(root->expiration_date)) {
        cout << "\nEXPIRED → " << root->name
             << "\nCode: " << root->code
             << "\nExpired On: " << root->expiration_date
             << "\n------------------------------";
    }

    listExpired(root->left);
    listExpired(root->right);
}

// ---------------------------- Main Function -----------------------------
int main() {
    Product* root = NULL;
    int choice, quantity;
    string code, name, dr, exp;
    float price;

    while (true) {
        cout << "\n\n--- PRODUCT INVENTORY SYSTEM (BST) ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. List Expired Items (Preorder)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
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
                cin >> quantity;
                cout << "Enter Date Received (DD/MM/YYYY): ";
                cin >> dr;
                cout << "Enter Expiration Date (DD/MM/YYYY): ";
                cin >> exp;

                root = insert(root, code, name, price, quantity, dr, exp);
                cout << "Product Added!\n";
                break;

            case 2:
                cout << "\n--- INVENTORY ITEMS (SORTED BY NAME) ---\n";
                inorder(root);
                break;

            case 3:
                cout << "\n--- EXPIRED PRODUCTS (PREORDER LIST) ---\n";
                listExpired(root);
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}