#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = nullptr;
    }
};

class PatientStack {
private:
    Node* topNode;

public:
    PatientStack() {
        topNode = nullptr;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void push(const string& patientID) {
        Node* newNode = new Node(patientID);
        newNode->next = topNode;
        topNode = newNode;
    }

    string pop() {
        if (isEmpty()) {
            cout << "No pending patient requests!\n";
            return "";
        }
        Node* temp = topNode;
        string handledID = temp->patientID;
        topNode = topNode->next;
        delete temp;
        return handledID;
    }

    string peek() const {
        if (isEmpty()) {
            return "No Active Requests";
        }
        return topNode->patientID;
    }

    void displayRequests() const {
        if (isEmpty()) {
            cout << "No patient requests remaining.\n\n";
            return;
        }

        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->patientID;
            if (temp == topNode) {
                cout << "  <-- (TOP / Next to Handle)";
            }
            cout << "\n";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~PatientStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    PatientStack hospitalQueue;

    hospitalQueue.push("P101");
    hospitalQueue.push("P102");
    hospitalQueue.push("P103");
    hospitalQueue.push("P104");

    cout << "--- All Patient Requests (TOP to Bottom) ---\n";
    hospitalQueue.displayRequests();

    cout << "Handling Latest Request (POP): " << hospitalQueue.pop() << "\n\n";

    cout << "New TOP Request: " << hospitalQueue.peek() << "\n\n";

    cout << "--- Remaining Patient Requests ---\n";
    hospitalQueue.displayRequests();

    return 0;
}