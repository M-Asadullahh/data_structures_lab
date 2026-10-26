#include <iostream>

using namespace std;

class Node {
public:
    int empID;
    Node* left;
    Node* right;

    Node(int id) {
        empID = id;
        left = nullptr;
        right = nullptr;
    }
};

class EmployeeBST {
private:
    Node* root;

    Node* insertHelper(Node* node, int id) {
        if (node == nullptr) {
            return new Node(id);
        }
        if (id < node->empID) {
            node->left = insertHelper(node->left, id);
        }
        else if (id > node->empID) {
            node->right = insertHelper(node->right, id);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteHelper(Node* node, int key) {
        if (node == nullptr) return nullptr;

        if (key < node->empID) {
            node->left = deleteHelper(node->left, key);
        }
        else if (key > node->empID) {
            node->right = deleteHelper(node->right, key);
        }
        else {
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
                node->empID = temp->empID;
                node->right = deleteHelper(node->right, temp->empID);
            }
        }
        return node;
    }

    void inOrderHelper(Node* node) const {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        cout << node->empID << " ";
        inOrderHelper(node->right);
    }

public:
    EmployeeBST() {
        root = nullptr;
    }

    void insert(int id) {
        root = insertHelper(root, id);
    }

    void remove(int id) {
        root = deleteHelper(root, id);
    }

    void displayInOrder() const {
        inOrderHelper(root);
        cout << "\n";
    }
};

int main() {
    EmployeeBST company;

    int employees[] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int e : employees) {
        company.insert(e);
    }

    cout << "Original Employee IDs: ";
    company.displayInOrder();

    int deleteID;
    cout << "\nEnter Employee ID to delete: ";
    cin >> deleteID;

    company.remove(deleteID);

    cout << "Remaining Employee IDs: ";
    company.displayInOrder();

    return 0;
}