#include <iostream>
#include <string>
using namespace std;

struct PatientNode {
    string patientID;
    PatientNode* next;
};

int main() {
    PatientNode* head = NULL;
    PatientNode* tail = NULL;

    int userChoice;
    while (true) {
        cout << "\n1. Add Patient\n2. Serve Patient\n3. Display Queue\n4. Exit\nEnter choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            string pID;
            cout << "Enter Patient ID: ";
            cin >> pID;

            PatientNode* newNode = new PatientNode();
            newNode->patientID = pID;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Patient added to queue.\n";
        }
        else if (userChoice == 2) {
            if (head == NULL) {
                cout << "No patients in queue.\n";
            }
            else {
                PatientNode* temp = head;
                cout << "Patient " << temp->patientID << " is being served.\n";

                head = head->next;
                if (head == NULL) {
                    tail = NULL;
                }

                delete temp;
            }
        }
        else if (userChoice == 3) {
            if (head == NULL) {
                cout << "Queue is empty.\n";
            }
            else {
                cout << "Waiting Patients:\n";
                PatientNode* current = head;
                while (current != NULL) {
                    cout << current->patientID;
                    if (current->next != NULL) {
                        cout << " -> ";
                    }
                    current = current->next;
                }
                cout << "\n";
            }
        }
        else if (userChoice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}