#include <iostream>

using namespace std;

class Node {
public:
    int patientID;
    Node* left;
    Node* right;

    Node(int id) {
        patientID = id;
        left = nullptr;
        right = nullptr;
    }
};

class HospitalBST {
private:
    Node* root;

    Node* insertHelper(Node* node, int id) {
        if (node == nullptr) {
            return new Node(id);
        }
        if (id < node->patientID) {
            node->left = insertHelper(node->left, id);
        }
        else if (id > node->patientID) {
            node->right = insertHelper(node->right, id);
        }
        return node;
    }

    void inOrder(Node* node) const {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->patientID << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) const {
        if (node == nullptr) return;
        cout << node->patientID << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) const {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->patientID << " ";
    }

public:
    HospitalBST() {
        root = nullptr;
    }

    void insert(int id) {
        root = insertHelper(root, id);
    }

    void displayTraversals() const {
        cout << "In-Order Traversal (Left, Root, Right)  : ";
        inOrder(root);
        cout << "\n";

        cout << "Pre-Order Traversal (Root, Left, Right) : ";
        preOrder(root);
        cout << "\n";

        cout << "Post-Order Traversal (Left, Right, Root): ";
        postOrder(root);
        cout << "\n\n";

        cout << "Note: In-Order Traversal displays patient IDs in ascending order.\n";
    }
};

int main() {
    HospitalBST hospital;

    int patients[] = { 40, 20, 60, 10, 30, 50, 70 };
    for (int p : patients) {
        hospital.insert(p);
    }

    hospital.displayTraversals();

    return 0;
}