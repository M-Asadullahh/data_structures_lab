#include <iostream>
#include <string>

using namespace std;

struct PatientNode {
    int patientID;
    string name;
    int age;
    PatientNode* next;
};

int main() {
    PatientNode* head = NULL;

    int choice;
    while (true) {
        cout << "\n1. Add Patient at End\n2. Add Emergency Patient at Beginning\n3. Search Patient\n4. Remove Patient\n5. Display Waiting List\n6. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, pAge;
            string pName;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> pName;
            cout << "Enter Patient Age: ";
            cin >> pAge;

            PatientNode* newNode = new PatientNode();
            newNode->patientID = id;
            newNode->name = pName;
            newNode->age = pAge;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            }
            else {
                PatientNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cout << "Patient added at the end.\n";
        }
        else if (choice == 2) {
            int id, pAge;
            string pName;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> pName;
            cout << "Enter Patient Age: ";
            cin >> pAge;

            PatientNode* newNode = new PatientNode();
            newNode->patientID = id;
            newNode->name = pName;
            newNode->age = pAge;
            newNode->next = head;
            head = newNode;

            cout << "Emergency patient added at the beginning.\n";
        }
        else if (choice == 3) {
            if (head == NULL) {
                cout << "Waiting list is empty.\n";
            }
            else {
                int searchID;
                cout << "Enter Patient ID to Search: ";
                cin >> searchID;

                bool found = false;
                PatientNode* ptr = head;
                while (ptr != NULL) {
                    if (ptr->patientID == searchID) {
                        cout << "Patient Found: ID = " << ptr->patientID << ", Name = " << ptr->name << ", Age = " << ptr->age << "\n";
                        found = true;
                        break;
                    }
                    ptr = ptr->next;
                }

                if (!found) {
                    cout << "Patient does not exist.\n";
                }
            }
        }
        else if (choice == 4) {
            if (head == NULL) {
                cout << "Waiting list is empty.\n";
            }
            else {
                int removeID;
                cout << "Enter Patient ID to Remove: ";
                cin >> removeID;

                if (head->patientID == removeID) {
                    PatientNode* delNode = head;
                    head = head->next;
                    delete delNode;
                    cout << "Patient removed after treatment.\n";
                }
                else {
                    PatientNode* prev = head;
                    PatientNode* curr = head->next;
                    bool found = false;

                    while (curr != NULL) {
                        if (curr->patientID == removeID) {
                            found = true;
                            prev->next = curr->next;
                            delete curr;
                            cout << "Patient removed after treatment.\n";
                            break;
                        }
                        prev = curr;
                        curr = curr->next;
                    }

                    if (!found) {
                        cout << "Patient does not exist.\n";
                    }
                }
            }
        }
        else if (choice == 5) {
            if (head == NULL) {
                cout << "No patients in the waiting list.\n";
            }
            else {
                cout << "Waiting Patients:\n";
                PatientNode* curr = head;
                while (curr != NULL) {
                    cout << "[ID: " << curr->patientID << " | Name: " << curr->name << " | Age: " << curr->age << "]";
                    if (curr->next != NULL) {
                        cout << " -> ";
                    }
                    curr = curr->next;
                }
                cout << "\n";
            }
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}