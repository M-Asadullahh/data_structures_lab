#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folderName;
    Node* left;
    Node* right;

    Node(string name) {
        folderName = name;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* current) {
    if (current == NULL) {
        return;
    }
    inorder(current->left);
    cout << current->folderName << "  ";
    inorder(current->right);
}

void preorder(Node* current) {
    if (current == NULL) {
        return;
    }
    cout << current->folderName << "  ";
    preorder(current->left);
    preorder(current->right);
}

void postorder(Node* current) {
    if (current == NULL) {
        return;
    }
    postorder(current->left);
    postorder(current->right);
    cout << current->folderName << "  ";
}

int main() {
    Node* computer = new Node("Computer");
    Node* documents = new Node("Documents");
    Node* pictures = new Node("Pictures");
    Node* work = new Node("Work");
    Node* school = new Node("School");
    Node* family = new Node("Family");
    Node* trips = new Node("Trips");

    computer->left = documents;
    computer->right = pictures;

    documents->left = work;
    documents->right = school;

    pictures->left = family;
    pictures->right = trips;

    cout << "In-order   (Left, Root, Right) : ";
    inorder(computer);
    cout << endl << endl;

    cout << "Pre-order  (Root, Left, Right) : ";
    preorder(computer);
    cout << endl << endl;

    cout << "Post-order (Left, Right, Root) : ";
    postorder(computer);
    cout << endl;

    return 0;
}