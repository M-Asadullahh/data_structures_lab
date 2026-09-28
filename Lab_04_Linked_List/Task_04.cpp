#include <iostream>

using namespace std;

struct StudentNode {
    int rollNum;
    StudentNode* next;
};

int main() {
    StudentNode* head = NULL;

    int opt;
    while (true) {
        cout << "\n1. Insert Student at Beginning\n2. Add Student at End\n3. Display Enrolled Students\n4. Search Student\n5. Exit\nEnter choice: ";
        cin >> opt;

        if (opt == 1) {
            int rNum;
            cout << "Enter Roll Number: ";
            cin >> rNum;

            StudentNode* newNode = new StudentNode();
            newNode->rollNum = rNum;
            newNode->next = head;
            head = newNode;

            cout << "Student added at the beginning.\n";
        }
        else if (opt == 2) {
            int rNum;
            cout << "Enter Roll Number: ";
            cin >> rNum;

            StudentNode* newNode = new StudentNode();
            newNode->rollNum = rNum;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            }
            else {
                StudentNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cout << "Student added at the end.\n";
        }
        else if (opt == 3) {
            if (head == NULL) {
                cout << "No enrolled students.\n";
            }
            else {
                cout << "Enrolled Students:\n";
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
        else if (opt == 4) {
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
        else if (opt == 5) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}