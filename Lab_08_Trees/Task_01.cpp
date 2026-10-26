#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string personName) {
        name = personName;
        left = nullptr;
        right = nullptr;
    }
};

class FamilyTree {
public:
    Node* root;

    FamilyTree() {
        root = nullptr;
    }

    void displayNodeInfo(Node* node) const {
        if (node == nullptr) return;

        cout << "Person: " << node->name << "\n";
        cout << "  Left Child : " << (node->left ? node->left->name : "None") << "\n";
        cout << "  Right Child: " << (node->right ? node->right->name : "None") << "\n\n";

        displayNodeInfo(node->left);
        displayNodeInfo(node->right);
    }
};

int main() {
    FamilyTree family;

    family.root = new Node("Grandfather");
    family.root->left = new Node("Father");
    family.root->right = new Node("Uncle");

    family.root->left->left = new Node("Self");
    family.root->left->right = new Node("Brother");

    family.root->right->left = new Node("Cousin1");
    family.root->right->right = new Node("Cousin2");

    cout << "--- Family Tree Structure ---\n\n";
    family.displayNodeInfo(family.root);

    return 0;
}