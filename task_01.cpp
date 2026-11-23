#include <iostream>
#include <string>
using namespace std;
class StudentNode {
public:
    string name;
    int rollNumber;
    int marks;
    StudentNode* left;
    StudentNode* right;
    StudentNode* parent;
    StudentNode(string n, int r, int m) {
        name = n;
        rollNumber = r;
        marks = m;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
class StudentHeap {
public:
    StudentNode* root;
    int count;
    StudentHeap() {
        root = NULL;
        count = 0;
    }
    void getNodes(StudentNode* nodes[]) {
        if (root == NULL) return;
        int front = 1;
        int back = 1;
        nodes[1] = root;
        while (front <= back) {
            StudentNode* current = nodes[front];
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
    void swapData(StudentNode* a, StudentNode* b) {
        string tempName = a->name;
        int tempRoll = a->rollNumber;
        int tempMarks = a->marks;
        a->name = b->name;
        a->rollNumber = b->rollNumber;
        a->marks = b->marks;
        b->name = tempName;
        b->rollNumber = tempRoll;
        b->marks = tempMarks;
    }
    void heapifyUp(StudentNode* node) {
        while (node->parent != NULL && node->marks > node->parent->marks) {
            swapData(node, node->parent);
            node = node->parent;
        }
    }
    void heapifyDown(StudentNode* node) {
        while (true) {
            StudentNode* largest = node;
            if (node->left != NULL && node->left->marks > largest->marks) {
                largest = node->left;
            }
            if (node->right != NULL && node->right->marks > largest->marks) {
                largest = node->right;
            }
            if (largest == node) break;
            swapData(node, largest);
            node = largest;
        }
    }
    void insert(string name, int rollNumber, int marks) {
        StudentNode* newNode = new StudentNode(name, rollNumber, marks);
        if (root == NULL) {
            root = newNode;
            count = 1;
            return;
        }
        StudentNode* nodes[100];
        getNodes(nodes);
        StudentNode* parent = nodes[(count + 1) / 2];
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
            cout << "Heap is empty" << endl;
            return;
        }
        if (count == 1) {
            delete root;
            root = NULL;
            count = 0;
            return;
        }
        StudentNode* nodes[100];
        getNodes(nodes);
        StudentNode* last = nodes[count];
        root->name = last->name;
        root->rollNumber = last->rollNumber;
        root->marks = last->marks;
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
            cout << "Heap is empty" << endl;
            return;
        }
        StudentNode* nodes[100];
        getNodes(nodes);
        for (int i = 1; i <= count; i++) {
            cout << i << ". " << nodes[i]->name << " | roll no: " << nodes[i]->rollNumber
                << " | marks: " << nodes[i]->marks << endl;
        }
    }
};
int main() {
    cout << "Task 1: student merit ranking (max heap)" << endl;
    StudentHeap studentHeap;
    studentHeap.insert("Ali", 101, 85);
    studentHeap.insert("Sara", 102, 92);
    studentHeap.insert("Hamza", 103, 78);
    studentHeap.insert("Ayesha", 104, 88);
    studentHeap.insert("Bilal", 105, 95);
    studentHeap.insert("Fatima", 106, 70);
    studentHeap.insert("Usman", 107, 81);
    cout << "Heap after inserting all students (level order):" << endl;
    studentHeap.display();
    cout << "Deleting student with highest marks: " << studentHeap.root->name
        << " (" << studentHeap.root->marks << ")" << endl;
    studentHeap.deleteRoot();
    cout << "Heap after deletion (level order):" << endl;
    studentHeap.display();
    cout << "Press enter to exit...";
    cin.get();
    return 0;
}