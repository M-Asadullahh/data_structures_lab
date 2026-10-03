#include <iostream>
#include <string>

using namespace std;

struct StudentNode {
    int rollNum;
    string name;
    string status;
    StudentNode* next;
};

int main() {
    StudentNode* head = NULL;

    int userOpt;
    while (true) {
        cout << "\n1. Add Student\n2. Search Student\n3. Delete Student\n4. Display Students\n5. Count Present Students\n6. Display Final Attendance List\n7. Exit\nEnter choice: ";
        cin >> userOpt;

        if (userOpt == 1) {
            int rNo;
            string stName, attStatus;
            cout << "Enter Roll Number: ";
            cin >> rNo;
            cout << "Enter Name: ";
            cin >> stName;
            cout << "Enter Status (Present/Absent): ";
            cin >> attStatus;

            StudentNode* temp = new StudentNode();
            temp->rollNum = rNo;
            temp->name = stName;
            temp->status = attStatus;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
            }
            else {
                StudentNode* ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = temp;
            }
            cout << "Student added to attendance list.\n";
        }
        else if (userOpt == 2) {
            if (head == NULL) {
                cout << "List is empty.\n";
            }
            else {
                int searchRoll;
                cout << "Enter Roll Number to Search: ";
                cin >> searchRoll;

                bool found = false;
                StudentNode* curr = head;
                while (curr != NULL) {
                    if (curr->rollNum == searchRoll) {
                        cout << "Student Found: Roll = " << curr->rollNum << ", Name = " << curr->name << ", Status = " << curr->status << "\n";
                        found = true;
                        break;
                    }
                    curr = curr->next;
                }

                if (!found) {
                    cout << "Student not found.\n";
                }
            }
        }
        else if (userOpt == 3) {
            if (head == NULL) {
                cout << "List is empty.\n";
            }
            else {
                int delRoll;
                cout << "Enter Roll Number to Delete: ";
                cin >> delRoll;

                if (head->rollNum == delRoll) {
                    StudentNode* delNode = head;
                    head = head->next;
                    delete delNode;
                    cout << "Student deleted successfully.\n";
                }
                else {
                    StudentNode* prev = head;
                    StudentNode* curr = head->next;
                    bool found = false;

                    while (curr != NULL) {
                        if (curr->rollNum == delRoll) {
                            found = true;
                            prev->next = curr->next;
                            delete curr;
                            cout << "Student deleted successfully.\n";
                            break;
                        }
                        prev = curr;
                        curr = curr->next;
                    }

                    if (!found) {
                        cout << "Student not found.\n";
                    }
                }
            }
        }
        else if (userOpt == 4 || userOpt == 6) {
            if (head == NULL) {
                cout << "Attendance list is empty.\n";
            }
            else {
                if (userOpt == 6) {
                    cout << "=== Final Attendance List ===\n";
                }
                else {
                    cout << "Attendance List:\n";
                }
                StudentNode* p = head;
                while (p != NULL) {
                    cout << "[Roll: " << p->rollNum << " | Name: " << p->name << " | Status: " << p->status << "]";
                    if (p->next != NULL) {
                        cout << " -> ";
                    }
                    p = p->next;
                }
                cout << "\n";
            }
        }
        else if (userOpt == 5) {
            int presentCount = 0;
            StudentNode* tracker = head;
            while (tracker != NULL) {
                if (tracker->status == "Present" || tracker->status == "present" || tracker->status == "P" || tracker->status == "p") {
                    presentCount++;
                }
                tracker = tracker->next;
            }
            cout << "Total students present: " << presentCount << "\n";
        }
        else if (userOpt == 7) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}