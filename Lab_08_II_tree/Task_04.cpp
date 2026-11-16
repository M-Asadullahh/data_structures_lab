#include <iostream>
using namespace std;

class Node {
public:
    int token;
    int height;
    Node* left;
    Node* right;

    Node(int tokenNumber) {
        token = tokenNumber;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* current) {
    if (current == NULL) {
        return 0;
    }
    return current->height;
}

int getBalanceFactor(Node* current) {
    if (current == NULL) {
        return 0;
    }
    return getHeight(current->left) - getHeight(current->right);
}

void updateHeight(Node* current) {
    int leftHeight = getHeight(current->left);
    int rightHeight = getHeight(current->right);

    if (leftHeight > rightHeight) {
        current->height = leftHeight + 1;
    }
    else {
        current->height = rightHeight + 1;
    }
}

Node* rightRotation(Node* oldRoot) {
    Node* newRoot = oldRoot->left;
    Node* movedSubtree = newRoot->right;

    newRoot->right = oldRoot;
    oldRoot->left = movedSubtree;

    updateHeight(oldRoot);
    updateHeight(newRoot);

    return newRoot;
}

Node* leftRotation(Node* oldRoot) {
    Node* newRoot = oldRoot->right;
    Node* movedSubtree = newRoot->left;

    newRoot->left = oldRoot;
    oldRoot->right = movedSubtree;

    updateHeight(oldRoot);
    updateHeight(newRoot);

    return newRoot;
}

Node* insertToken(Node* root, int tokenNumber) {
    if (root == NULL) {
        return new Node(tokenNumber);
    }

    if (tokenNumber < root->token) {
        root->left = insertToken(root->left, tokenNumber);
    }
    else if (tokenNumber > root->token) {
        root->right = insertToken(root->right, tokenNumber);
    }
    else {
        return root;
    }

    updateHeight(root);
    int balance = getBalanceFactor(root);

    if (balance > 1 && tokenNumber < root->left->token) {
        cout << "LL case at node " << root->token << " -> Right Rotation" << endl;
        return rightRotation(root);
    }

    if (balance < -1 && tokenNumber > root->right->token) {
        cout << "RR case at node " << root->token << " -> Left Rotation" << endl;
        return leftRotation(root);
    }

    if (balance > 1 && tokenNumber > root->left->token) {
        cout << "LR case at node " << root->token << " -> Left then Right Rotation" << endl;
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if (balance < -1 && tokenNumber < root->right->token) {
        cout << "RL case at node " << root->token << " -> Right then Left Rotation" << endl;
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void inorder(Node* current) {
    if (current == NULL) {
        return;
    }
    inorder(current->left);
    cout << "Token " << current->token
        << "  (height = " << current->height
        << ", balance factor = " << getBalanceFactor(current) << ")" << endl;
    inorder(current->right);
}

void showTree(Node* current, int space) {
    if (current == NULL) {
        return;
    }

    space = space + 8;
    showTree(current->right, space);

    cout << endl;
    for (int i = 8; i < space; i++) {
        cout << " ";
    }
    cout << current->token << endl;

    showTree(current->left, space);
}

int main() {
    Node* root = NULL;
    int tokens[7] = { 15, 25, 35, 45, 55, 65, 75 };

    for (int i = 0; i < 7; i++) {
        cout << "Inserting " << tokens[i] << endl;
        root = insertToken(root, tokens[i]);
    }

    cout << endl << "In-order Traversal:" << endl;
    cout << "-------------------" << endl;
    inorder(root);

    cout << endl << "Final Balanced Tree (root on the left, right side on top):" << endl;
    showTree(root, 0);

    return 0;
}