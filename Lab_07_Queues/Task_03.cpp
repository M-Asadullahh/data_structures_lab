#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string id;
    int priority;
};

class PriorityPatientQueue {
private:
    static const int CAPACITY = 10;
    Patient arr[CAPACITY];
    int count;

public:
    PriorityPatientQueue() {
        count = 0;
    }

    bool isFull() const {
        return count == CAPACITY;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void enqueue(string patientID, int priority) {
        if (isFull()) {
            cout << "Emergency Queue Full! Cannot accept " << patientID << ".\n";
            return;
        }

        int i = count - 1;
        while (i >= 0 && arr[i].priority > priority) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1].id = patientID;
        arr[i + 1].priority = priority;
        count++;

        cout << "Patient " << patientID << " (Priority " << priority << ") added.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty! No waiting patients.\n";
            return;
        }
        cout << "Treating patient: " << arr[0].id << " (Priority " << arr[0].priority << ")\n";
        for (int i = 0; i < count - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void displayPatients() const {
        if (isEmpty()) {
            cout << "No patients waiting.\n\n";
            return;
        }
        cout << "--- Waiting Patients (Highest Priority First) ---\n";
        for (int i = 0; i < count; ++i) {
            cout << "Patient ID: " << arr[i].id << " | Priority: " << arr[i].priority << "\n";
        }
        cout << "\n";
    }
};

int main() {
    PriorityPatientQueue emergencyRoom;

    emergencyRoom.enqueue("P101", 3);
    emergencyRoom.enqueue("P102", 1);
    emergencyRoom.enqueue("P103", 2);

    emergencyRoom.displayPatients();

    emergencyRoom.dequeue();

    emergencyRoom.displayPatients();

    return 0;
}