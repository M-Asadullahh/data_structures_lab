#include <iostream>
#include <string>
using namespace std;
class PatientNode {
public:
    string name;
    int patientId;
    int priority;
    PatientNode* left;
    PatientNode* right;
    PatientNode* parent;
    PatientNode(string n, int id, int p) {
        name = n;
        patientId = id;
        priority = p;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
class PatientHeap {
public:
    PatientNode* root;
    int count;
    PatientHeap() {
        root = NULL;
        count = 0;
    }
    void getNodes(PatientNode* nodes[]) {
        if (root == NULL) return;
        int front = 1;
        int back = 1;
        nodes[1] = root;
        while (front <= back) {
            PatientNode* current = nodes[front];
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
    void swapData(PatientNode* a, PatientNode* b) {
        string tempName = a->name;
        int tempId = a->patientId;
        int tempPriority = a->priority;
        a->name = b->name;
        a->patientId = b->patientId;
        a->priority = b->priority;
        b->name = tempName;
        b->patientId = tempId;
        b->priority = tempPriority;
    }
    void heapifyUp(PatientNode* node) {
        while (node->parent != NULL && node->priority > node->parent->priority) {
            swapData(node, node->parent);
            node = node->parent;
        }
    }
    void heapifyDown(PatientNode* node) {
        while (true) {
            PatientNode* largest = node;
            if (node->left != NULL && node->left->priority > largest->priority) {
                largest = node->left;
            }
            if (node->right != NULL && node->right->priority > largest->priority) {
                largest = node->right;
            }
            if (largest == node) break;
            swapData(node, largest);
            node = largest;
        }
    }
    void insert(string name, int patientId, int priority) {
        PatientNode* newNode = new PatientNode(name, patientId, priority);
        if (root == NULL) {
            root = newNode;
            count = 1;
            return;
        }
        PatientNode* nodes[100];
        getNodes(nodes);
        PatientNode* parent = nodes[(count + 1) / 2];
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
            cout << "No patients left" << endl;
            return;
        }
        if (count == 1) {
            delete root;
            root = NULL;
            count = 0;
            return;
        }
        PatientNode* nodes[100];
        getNodes(nodes);
        PatientNode* last = nodes[count];
        root->name = last->name;
        root->patientId = last->patientId;
        root->priority = last->priority;
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
            cout << "No patients left" << endl;
            return;
        }
        PatientNode* nodes[100];
        getNodes(nodes);
        for (int i = 1; i <= count; i++) {
            cout << i << ". " << nodes[i]->name << " | id: " << nodes[i]->patientId
                << " | priority: " << nodes[i]->priority << endl;
        }
    }
    void showHighestPriority() {
        if (root == NULL) {
            cout << "No patients left" << endl;
            return;
        }
        cout << "Highest priority patient: " << root->name << " | id: " << root->patientId
            << " | priority: " << root->priority << endl;
    }
};
int main() {
    cout << "Task 2: hospital emergency system (max heap)" << endl;
    PatientHeap patientHeap;
    patientHeap.insert("Zain", 201, 5);
    patientHeap.insert("Hina", 202, 9);
    patientHeap.insert("Kamran", 203, 3);
    patientHeap.insert("Noor", 204, 7);
    patientHeap.insert("Rabia", 205, 10);
    patientHeap.insert("Danish", 206, 6);
    cout << "All patients (level order):" << endl;
    patientHeap.display();
    patientHeap.showHighestPriority();
    cout << "Treating the highest priority patient and removing from heap..." << endl;
    patientHeap.deleteRoot();
    cout << "Heap after deletion (level order):" << endl;
    patientHeap.display();
    cout << "Next patient who needs treatment:" << endl;
    patientHeap.showHighestPriority();
    cout << "Press enter to exit...";
    cin.get();
    return 0;
}