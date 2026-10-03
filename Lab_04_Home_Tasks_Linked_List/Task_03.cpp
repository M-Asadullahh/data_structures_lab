#include <iostream>
#include <string>

using namespace std;

struct OrderNode {
    string orderID;
    string custName;
    string foodItem;
    OrderNode* next;
};

int main() {
    OrderNode* head = NULL;

    int selection;
    while (true) {
        cout << "\n1. Add Order at End\n2. Add Urgent Order at Beginning\n3. Display Pending Orders\n4. Search Order\n5. Deliver/Remove Order\n6. Exit\nEnter choice: ";
        cin >> selection;

        if (selection == 1) {
            string oID, cName, fItem;
            cout << "Enter Order ID: ";
            cin >> oID;
            cout << "Enter Customer Name: ";
            cin >> cName;
            cout << "Enter Food Item: ";
            cin >> fItem;

            OrderNode* temp = new OrderNode();
            temp->orderID = oID;
            temp->custName = cName;
            temp->foodItem = fItem;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
            }
            else {
                OrderNode* p = head;
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = temp;
            }
            cout << "Order added successfully.\n";
        }
        else if (selection == 2) {
            string oID, cName, fItem;
            cout << "Enter Urgent Order ID: ";
            cin >> oID;
            cout << "Enter Customer Name: ";
            cin >> cName;
            cout << "Enter Food Item: ";
            cin >> fItem;

            OrderNode* temp = new OrderNode();
            temp->orderID = oID;
            temp->custName = cName;
            temp->foodItem = fItem;
            temp->next = head;
            head = temp;

            cout << "Urgent order added at the front.\n";
        }
        else if (selection == 3) {
            if (head == NULL) {
                cout << "No pending orders.\n";
            }
            else {
                cout << "Pending Orders:\n";
                OrderNode* curr = head;
                while (curr != NULL) {
                    cout << curr->orderID;
                    if (curr->next != NULL) {
                        cout << " -> ";
                    }
                    curr = curr->next;
                }
                cout << "\n";
            }
        }
        else if (selection == 4) {
            if (head == NULL) {
                cout << "No orders to search.\n";
            }
            else {
                string searchID;
                cout << "Enter Order ID to Search: ";
                cin >> searchID;

                bool found = false;
                OrderNode* ptr = head;
                while (ptr != NULL) {
                    if (ptr->orderID == searchID) {
                        cout << "Order Found: ID = " << ptr->orderID << ", Name = " << ptr->custName << ", Item = " << ptr->foodItem << "\n";
                        found = true;
                        break;
                    }
                    ptr = ptr->next;
                }

                if (!found) {
                    cout << "Order not found.\n";
                }
            }
        }
        else if (selection == 5) {
            if (head == NULL) {
                cout << "No orders available to deliver.\n";
            }
            else {
                string delID;
                cout << "Enter Order ID to Remove (Delivered): ";
                cin >> delID;

                if (head->orderID == delID) {
                    OrderNode* delNode = head;
                    head = head->next;
                    delete delNode;
                    cout << "Order " << delID << " delivered.\n";
                }
                else {
                    OrderNode* prev = head;
                    OrderNode* curr = head->next;
                    bool found = false;

                    while (curr != NULL) {
                        if (curr->orderID == delID) {
                            found = true;
                            prev->next = curr->next;
                            delete curr;
                            cout << "Order " << delID << " delivered.\n";
                            break;
                        }
                        prev = curr;
                        curr = curr->next;
                    }

                    if (!found) {
                        cout << "Order ID not found.\n";
                    }
                }
            }
        }
        else if (selection == 6) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}