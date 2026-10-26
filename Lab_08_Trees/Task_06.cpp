#include <iostream>

using namespace std;

class Node {
public:
    int productID;
    Node* left;
    Node* right;

    Node(int id) {
        productID = id;
        left = nullptr;
        right = nullptr;
    }
};

class InventoryBST {
private:
    Node* root;

    Node* insertHelper(Node* node, int id, bool& isDuplicate) {
        if (node == nullptr) {
            return new Node(id);
        }
        if (id < node->productID) {
            node->left = insertHelper(node->left, id, isDuplicate);
        }
        else if (id > node->productID) {
            node->right = insertHelper(node->right, id, isDuplicate);
        }
        else {
            isDuplicate = true;
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteHelper(Node* node, int id, bool& found) {
        if (node == nullptr) return nullptr;

        if (id < node->productID) {
            node->left = deleteHelper(node->left, id, found);
        }
        else if (id > node->productID) {
            node->right = deleteHelper(node->right, id, found);
        }
        else {
            found = true;
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = findMin(node->right);
                node->productID = temp->productID;
                node->right = deleteHelper(node->right, temp->productID, found);
            }
        }
        return node;
    }

    bool searchHelper(Node* node, int id) const {
        if (node == nullptr) return false;
        if (node->productID == id) return true;
        if (id < node->productID) return searchHelper(node->left, id);
        return searchHelper(node->right, id);
    }

    void inOrder(Node* node) const {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->productID << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) const {
        if (node == nullptr) return;
        cout << node->productID << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) const {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->productID << " ";
    }

    void clearTree(Node* node) {
        if (node == nullptr) return;
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }

public:
    InventoryBST() {
        root = nullptr;
    }

    ~InventoryBST() {
        clearTree(root);
    }

    void insertProduct(int id) {
        bool isDuplicate = false;
        root = insertHelper(root, id, isDuplicate);
        if (isDuplicate) {
            cout << "Duplicate Product ID (" << id << ") ignored!\n";
        }
        else {
            cout << "Product ID " << id << " inserted successfully.\n";
        }
    }

    void searchProduct(int id) const {
        if (searchHelper(root, id)) {
            cout << "Product ID " << id << " found in inventory.\n";
        }
        else {
            cout << "Product ID " << id << " NOT found in inventory.\n";
        }
    }

    void deleteProduct(int id) {
        bool found = false;
        root = deleteHelper(root, id, found);
        if (found) {
            cout << "Product ID " << id << " deleted successfully.\n";
        }
        else {
            cout << "Product ID " << id << " NOT found to delete.\n";
        }
    }

    void displayInOrder() const {
        if (root == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "In-Order: ";
        inOrder(root);
        cout << "\n";
    }

    void displayPreOrder() const {
        if (root == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "Pre-Order: ";
        preOrder(root);
        cout << "\n";
    }

    void displayPostOrder() const {
        if (root == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "Post-Order: ";
        postOrder(root);
        cout << "\n";
    }
};

int main() {
    InventoryBST store;
    int choice, id;

    do {
        cout << "\n--- ONLINE STORE INVENTORY MENU ---\n";
        cout << "1. Insert Product ID\n";
        cout << "2. Search Product ID\n";
        cout << "3. Delete Product ID\n";
        cout << "4. Display In-Order Traversal\n";
        cout << "5. Display Pre-Order Traversal\n";
        cout << "6. Display Post-Order Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Product ID to insert: ";
            cin >> id;
            store.insertProduct(id);
            break;
        case 2:
            cout << "Enter Product ID to search: ";
            cin >> id;
            store.searchProduct(id);
            break;
        case 3:
            cout << "Enter Product ID to delete: ";
            cin >> id;
            store.deleteProduct(id);
            break;
        case 4:
            store.displayInOrder();
            break;
        case 5:
            store.displayPreOrder();
            break;
        case 6:
            store.displayPostOrder();
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}