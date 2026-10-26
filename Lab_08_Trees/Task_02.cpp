#include <iostream>

using namespace std;

class Node {
public:
    int rollNo;
    Node* left;
    Node* right;

    Node(int val) {
        rollNo = val;
        left = nullptr;
        right = nullptr;
    }
};

class StudentBST {
private:
    Node* root;

    Node* insertHelper(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->rollNo) {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->rollNo) {
            node->right = insertHelper(node->right, val);
        }
        return node;
    }

    void inOrderHelper(Node* node) const {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        cout << node->rollNo << " ";
        inOrderHelper(node->right);
    }

public:
    StudentBST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertHelper(root, val);
    }

    void displayInOrder() const {
        inOrderHelper(root);
        cout << "\n";
    }
};

int main() {
    StudentBST bst;

    int initialRolls[] = { 45, 25, 65, 15, 35, 55, 75 };
    for (int r : initialRolls) {
        bst.insert(r);
    }

    cout << "Initial Roll Numbers (In-Order): ";
    bst.displayInOrder();

    int user1, user2;
    cout << "\nEnter first additional roll number: ";
    cin >> user1;
    bst.insert(user1);

    cout << "Enter second additional roll number: ";
    cin >> user2;
    bst.insert(user2);

    cout << "\nUpdated Roll Numbers in Ascending Order: ";
    bst.displayInOrder();

    return 0;
}