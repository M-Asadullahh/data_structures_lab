#include <iostream>

using namespace std;

class StationDeque {
private:
    static const int CAPACITY = 5;
    int arr[CAPACITY];
    int front;
    int rear;
    int count;

public:
    StationDeque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() const {
        return count == CAPACITY;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void insertFront(int id) {
        if (isFull()) {
            cout << "Deque Full! Cannot insert " << id << " at front.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            front = (front - 1 + CAPACITY) % CAPACITY;
        }
        arr[front] = id;
        count++;
        cout << "Inserted " << id << " at Front.\n";
    }

    void insertRear(int id) {
        if (isFull()) {
            cout << "Deque Full! Cannot insert " << id << " at rear.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % CAPACITY;
        }
        arr[rear] = id;
        count++;
        cout << "Inserted " << id << " at Rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Empty! Cannot delete from front.\n";
            return;
        }
        cout << "Removed from Front: " << arr[front] << "\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % CAPACITY;
        }
        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Empty! Cannot delete from rear.\n";
            return;
        }
        cout << "Removed from Rear: " << arr[rear] << "\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            rear = (rear - 1 + CAPACITY) % CAPACITY;
        }
        count--;
    }

    void displayDeque() const {
        if (isEmpty()) {
            cout << "Passenger Deque is empty.\n\n";
            return;
        }
        cout << "Passenger Requests (Front to Rear): ";
        int index = front;
        for (int i = 0; i < count; ++i) {
            cout << arr[index] << " ";
            index = (index + 1) % CAPACITY;
        }
        cout << "\n\n";
    }
};

int main() {
    StationDeque station;

    station.insertRear(301);
    station.insertRear(302);
    station.insertFront(300);

    station.displayDeque();

    station.deleteFront();
    station.displayDeque();

    station.deleteRear();
    station.displayDeque();

    return 0;
}