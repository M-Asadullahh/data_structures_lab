#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
        next = nullptr;
    }
};

class RestaurantOrderStack {
private:
    Node* topNode;

public:
    RestaurantOrderStack() {
        topNode = nullptr;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void push(const string& id) {
        Node* newNode = new Node(id);
        newNode->next = topNode;
        topNode = newNode;
    }

    string pop() {
        if (isEmpty()) {
            cout << "No orders to process!\n";
            return "";
        }
        Node* temp = topNode;
        string processedID = temp->orderID;
        topNode = topNode->next;
        delete temp;
        return processedID;
    }

    string peek() const {
        if (isEmpty()) {
            return "No Active Orders";
        }
        return topNode->orderID;
    }

    void displayOrders() const {
        if (isEmpty()) {
            cout << "Order stack is empty.\n\n";
            return;
        }

        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->orderID;
            if (temp == topNode) {
                cout << "  <-- (TOP / Next to Process)";
            }
            cout << "\n";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~RestaurantOrderStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    RestaurantOrderStack restaurantStack;

    restaurantStack.push("ORD-101");
    restaurantStack.push("ORD-102");
    restaurantStack.push("ORD-103");
    restaurantStack.push("ORD-104");

    cout << "--- All Orders (TOP to Bottom) ---\n";
    restaurantStack.displayOrders();

    cout << "Processing 1st Order (POP): " << restaurantStack.pop() << "\n";
    cout << "Processing 2nd Order (POP): " << restaurantStack.pop() << "\n\n";

    cout << "Current TOP Order: " << restaurantStack.peek() << "\n\n";

    cout << "--- Remaining Orders ---\n";
    restaurantStack.displayOrders();

    cout << "Is Stack Empty? " << (restaurantStack.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}