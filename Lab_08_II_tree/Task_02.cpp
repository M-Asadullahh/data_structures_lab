#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string categoryName) {
        category = categoryName;
        left = NULL;
        right = NULL;
    }
};

void bfsTraversal(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<Node*> waitingLine;
    waitingLine.push(root);

    while (!waitingLine.empty()) {
        Node* current = waitingLine.front();
        waitingLine.pop();

        cout << current->category << endl;

        if (current->left != NULL) {
            waitingLine.push(current->left);
        }
        if (current->right != NULL) {
            waitingLine.push(current->right);
        }
    }
}

int main() {
    Node* store = new Node("Online Store");
    Node* electronics = new Node("Electronics");
    Node* clothing = new Node("Clothing");
    Node* mobiles = new Node("Mobiles");
    Node* laptops = new Node("Laptops");
    Node* men = new Node("Men");
    Node* women = new Node("Women");
    Node* accessories = new Node("Accessories");

    store->left = electronics;
    store->right = clothing;

    electronics->left = mobiles;
    electronics->right = laptops;

    clothing->left = men;
    clothing->right = women;

    mobiles->left = accessories;

    cout << "Product Categories in BFS order:" << endl;
    cout << "--------------------------------" << endl;
    bfsTraversal(store);

    return 0;
}