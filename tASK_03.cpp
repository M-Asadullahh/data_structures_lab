#include <iostream>
#include <string>
using namespace std;
class OrderNode {
public:
    int orderId;
    string customerName;
    int amount;
    OrderNode* left;
    OrderNode* right;
    OrderNode* parent;
    OrderNode(int id, string n, int a) {
        orderId = id;
        customerName = n;
        amount = a;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
class OrderHeap {
public:
    OrderNode* root;
    int count;
    OrderHeap() {
        root = NULL;
        count = 0;
    }
    void getNodes(OrderNode* nodes[]) {
        if (root == NULL) return;
        int front = 1;
        int back = 1;
        nodes[1] = root;
        while (front <= back) {
            OrderNode* current = nodes[front];
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
    void swapData(OrderNode* a, OrderNode* b) {
        int tempId = a->orderId;
        string tempName = a->customerName;
        int tempAmount = a->amount;
        a->orderId = b->orderId;
        a->customerName = b->customerName;
        a->amount = b->amount;
        b->orderId = tempId;
        b->customerName = tempName;
        b->amount = tempAmount;
    }
    void heapifyUp(OrderNode* node) {
        while (node->parent != NULL && node->amount > node->parent->amount) {
            swapData(node, node->parent);
            node = node->parent;
        }
    }
    void heapifyDown(OrderNode* node) {
        while (true) {
            OrderNode* largest = node;
            if (node->left != NULL && node->left->amount > largest->amount) {
                largest = node->left;
            }
            if (node->right != NULL && node->right->amount > largest->amount) {
                largest = node->right;
            }
            if (largest == node) break;
            swapData(node, largest);
            node = largest;
        }
    }
    void insert(int orderId, string customerName, int amount) {
        OrderNode* newNode = new OrderNode(orderId, customerName, amount);
        if (root == NULL) {
            root = newNode;
            count = 1;
            return;
        }
        OrderNode* nodes[100];
        getNodes(nodes);
        OrderNode* parent = nodes[(count + 1) / 2];
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
        if (root == NULL) return;
        if (count == 1) {
            delete root;
            root = NULL;
            count = 0;
            return;
        }
        OrderNode* nodes[100];
        getNodes(nodes);
        OrderNode* last = nodes[count];
        root->orderId = last->orderId;
        root->customerName = last->customerName;
        root->amount = last->amount;
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
        OrderNode* nodes[100];
        getNodes(nodes);
        for (int i = 1; i <= count; i++) {
            cout << i << ". Order id: " << nodes[i]->orderId << " | customer: " << nodes[i]->customerName
                << " | amount: " << nodes[i]->amount << endl;
        }
    }
    void heapSort() {
        int deletedAmounts[100];
        int total = 0;
        while (root != NULL) {
            deletedAmounts[total] = root->amount;
            total++;
            deleteRoot();
        }
        cout << "Deleted amounts (largest to smallest): ";
        for (int i = 0; i < total; i++) {
            if (i > 0) cout << " ";
            cout << deletedAmounts[i];
        }
        cout << endl;
        cout << "Order amounts in ascending order: ";
        for (int i = total - 1; i >= 0; i--) {
            if (i < total - 1) cout << " ";
            cout << deletedAmounts[i];
        }
        cout << endl;
    }
};
int main() {
    cout << "Task 3: online order sorting (heap sort)" << endl;
    OrderHeap orderHeap;
    orderHeap.insert(301, "Ahmed", 4500);
    orderHeap.insert(302, "Maria", 1200);
    orderHeap.insert(303, "Taha", 7800);
    orderHeap.insert(304, "Iqra", 3000);
    orderHeap.insert(305, "Saad", 9500);
    orderHeap.insert(306, "Mehak", 2100);
    cout << "Max heap after inserting orders (level order):" << endl;
    orderHeap.display();
    orderHeap.heapSort();
    cout << "Press enter to exit...";
    cin.get();
    return 0;
}