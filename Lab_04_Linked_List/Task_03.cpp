#include <iostream>
#include <string>

using namespace std;

struct CartNode {
    string prodID;
    CartNode* next;
};

int main() {
    CartNode* head = NULL;
    CartNode* tail = NULL;

    int opt;
    while (true) {
        cout << "\n1. Add Product\n2. Remove Product\n3. Display Cart\n4. Exit\nEnter choice: ";
        cin >> opt;

        if (opt == 1) {
            string id;
            cout << "Enter Product ID: ";
            cin >> id;

            CartNode* temp = new CartNode();
            temp->prodID = id;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
            cout << "Product added to cart.\n";
        }
        else if (opt == 2) {
            if (head == NULL) {
                cout << "Cart is empty.\n";
            }
            else {
                string removeID;
                cout << "Enter Product ID to remove: ";
                cin >> removeID;

                if (head->prodID == removeID) {
                    CartNode* delNode = head;
                    head = head->next;
                    if (head == NULL) {
                        tail = NULL;
                    }
                    delete delNode;
                    cout << "Product removed.\n";
                }
                else {
                    CartNode* prev = head;
                    CartNode* curr = head->next;
                    bool found = false;

                    while (curr != NULL) {
                        if (curr->prodID == removeID) {
                            found = true;
                            prev->next = curr->next;
                            if (curr == tail) {
                                tail = prev;
                            }
                            delete curr;
                            cout << "Product removed.\n";
                            break;
                        }
                        prev = curr;
                        curr = curr->next;
                    }

                    if (!found) {
                        cout << "Product ID not found in cart.\n";
                    }
                }
            }
        }
        else if (opt == 3) {
            if (head == NULL) {
                cout << "Shopping Cart is empty.\n";
            }
            else {
                cout << "Shopping Cart:\n";
                CartNode* ptr = head;
                while (ptr != NULL) {
                    cout << ptr->prodID;
                    if (ptr->next != NULL) {
                        cout << " -> ";
                    }
                    ptr = ptr->next;
                }
                cout << "\n";
            }
        }
        else if (opt == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}