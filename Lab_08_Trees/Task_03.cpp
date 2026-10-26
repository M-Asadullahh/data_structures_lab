#include <iostream>

using namespace std;

class Node {
public:
    int bookID;
    Node* left;
    Node* right;

    Node(int id) {
        bookID = id;
        left = nullptr;
        right = nullptr;
    }
};

class LibraryBST {
private:
    Node* root;

    Node* insertHelper(Node* node, int id) {
        if (node == nullptr) {
            return new Node(id);
        }
        if (id < node->bookID) {
            node->left = insertHelper(node->left, id);
        }
        else if (id > node->bookID) {
            node->right = insertHelper(node->right, id);
        }
        return node;
    }

public:
    LibraryBST() {
        root = nullptr;
    }

    void insert(int id) {
        root = insertHelper(root, id);
    }

    void search(int target) const {
        Node* current = root;
        int comparisons = 0;
        bool found = false;

        while (current != nullptr) {
            comparisons++;
            if (current->bookID == target) {
                found = true;
                break;
            }
            else if (target < current->bookID) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (found) {
            cout << "Book Found!\n";
        }
        else {
            cout << "Book Not Found.\n";
        }
        cout << "Number of comparisons made: " << comparisons << "\n";
    }
};

int main() {
    LibraryBST library;

    int books[] = { 40, 20, 60, 10, 30, 50, 70 };
    for (int b : books) {
        library.insert(b);
    }

    int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    library.search(searchID);

    return 0;
}