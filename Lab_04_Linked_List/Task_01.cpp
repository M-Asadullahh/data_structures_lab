#include <iostream>
using namespace std;

struct StudentNode {
    int rollNum;
    StudentNode* next;
};

int main() {        
    StudentNode* head = NULL;
    StudentNode* tail = NULL;

    int choice;
    while (true) {
        cout << "\n1. Add Student\n2. Display Students\n3. Search Student\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            cout << "Enter Roll Number: ";
            cin >> roll;

            StudentNode* temp = new StudentNode();
            temp->rollNum = roll;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
            cout << "Student added successfully.\n";
        }
        else if (choice == 2) {
            if (head == NULL) {
                cout << "No students registered.\n";
            }
            else {
                cout << "Registered Students:\n";
                StudentNode* curr = head;
                while (curr != NULL) {
                    cout << curr->rollNum;
                    if (curr->next != NULL) {
                        cout << " -> ";
                    }
                    curr = curr->next;
                }
                cout << "\n";
            }
        }
        else if (choice == 3) {
            if (head == NULL) {
                cout << "List is empty.\n";
            }
            else {
                int searchRoll;
                cout << "Enter Roll Number to Search: ";
                cin >> searchRoll;

                bool found = false;
                StudentNode* ptr = head;
                while (ptr != NULL) {
                    if (ptr->rollNum == searchRoll) {
                        found = true;
                        break;
                    }
                    ptr = ptr->next;
                }

                if (found) {
                    cout << "Student Found\n";
                }
                else {
                    cout << "Student Not Found\n";
                }
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}