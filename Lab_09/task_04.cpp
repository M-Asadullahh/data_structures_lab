#include <iostream>
#include <string>
using namespace std;
class MedicineNode {
public:
    string name;
    int medicineId;
    int expiryDate;
    MedicineNode* left;
    MedicineNode* right;
    MedicineNode* parent;
    MedicineNode(string n, int id, int date) {
        name = n;
        medicineId = id;
        expiryDate = date;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
class MedicineHeap {
public:
    MedicineNode* root;
    int count;
    MedicineHeap() {
        root = NULL;
        count = 0;
    }
    void getNodes(MedicineNode* nodes[]) {
        if (root == NULL) return;
        int front = 1;
        int back = 1;
        nodes[1] = root;
        while (front <= back) {
            MedicineNode* current = nodes[front];
            front++;
            if (current->left != NULL) {
                back++;
                nodes[back] = current->left;
            }
            if (current->right != NULL) {
                back++;
                nodes[back] = current->right;
            }
        }
    }
    void swapData(MedicineNode* a, MedicineNode* b) {
        string tempName = a->name;
        int tempId = a->medicineId;
        int tempDate = a->expiryDate;
        a->name = b->name;
        a->medicineId = b->medicineId;
        a->expiryDate = b->expiryDate;
        b->name = tempName;
        b->medicineId = tempId;
        b->expiryDate = tempDate;
    }
    void heapifyUp(MedicineNode* node) {
        while (node->parent != NULL && node->expiryDate < node->parent->expiryDate) {
            swapData(node, node->parent);
            node = node->parent;
        }
    }
    void heapifyDown(MedicineNode* node) {
        while (true) {
            MedicineNode* smallest = node;
            if (node->left != NULL && node->left->expiryDate < smallest->expiryDate) {
                smallest = node->left;
            }
            if (node->right != NULL && node->right->expiryDate < smallest->expiryDate) {
                smallest = node->right;
            }
            if (smallest == node) break;
            swapData(node, smallest);
            node = smallest;
        }
    }
    void insert(string name, int medicineId, int expiryDate) {
        MedicineNode* newNode = new MedicineNode(name, medicineId, expiryDate);
        if (root == NULL) {
            root = newNode;
            count = 1;
            return;
        }
        MedicineNode* nodes[100];
        getNodes(nodes);
        MedicineNode* parent = nodes[(count + 1) / 2];
        if (parent->left == NULL) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
        newNode->parent = parent;
        count++;
        heapifyUp(newNode);
    }
    void deleteRoot() {
        if (root == NULL) {
            cout << "No medicines left" << endl;
            return;
        }
        if (count == 1) {
            delete root;
            root = NULL;
            count = 0;
            return;
        }
        MedicineNode* nodes[100];
        getNodes(nodes);
        MedicineNode* last = nodes[count];
        root->name = last->name;
        root->medicineId = last->medicineId;
        root->expiryDate = last->expiryDate;
        if (last->parent->right == last) {
            last->parent->right = NULL;
        }
        else {
            last->parent->left = NULL;
        }
        delete last;
        count--;
        heapifyDown(root);
    }
    void display() {
        if (root == NULL) {
            cout << "No medicines left" << endl;
            return;
        }
        MedicineNode* nodes[100];
        getNodes(nodes);
        for (int i = 1; i <= count; i++) {
            cout << i << ". " << nodes[i]->name << " | id: " << nodes[i]->medicineId
                << " | expiry: " << nodes[i]->expiryDate << endl;
        }
    }
};
int main() {
    cout << "Task 4: medicine expiry management (min heap)" << endl;
    MedicineHeap medicineHeap;
    medicineHeap.insert("Panadol", 401, 20270315);
    medicineHeap.insert("Brufen", 402, 20260901);
    medicineHeap.insert("Augmentin", 403, 20281120);
    medicineHeap.insert("Disprin", 404, 20270105);
    medicineHeap.insert("Flagyl", 405, 20260715);
    medicineHeap.insert("Calpol", 406, 20271230);
    cout << "Min heap after inserting medicines (level order):" << endl;
    medicineHeap.display();
    cout << "Medicine with nearest expiry date: " << medicineHeap.root->name
        << " (" << medicineHeap.root->expiryDate << ")" << endl;
    cout << "Deleting it..." << endl;
    medicineHeap.deleteRoot();
    cout << "Heap after deletion (level order):" << endl;
    medicineHeap.display();
    cout << "Press enter to exit...";
    cin.get();
    return 0;
}