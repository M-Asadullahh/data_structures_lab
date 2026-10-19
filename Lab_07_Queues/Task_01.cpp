#include <iostream>

using namespace std;

class BankQueue {
private:
    static const int CAPACITY = 5;
    int arr[CAPACITY];
    int front;
    int rear;

public:
    BankQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() const {
        return rear == CAPACITY - 1;
    }

    bool isEmpty() const {
        return front == -1 || front > rear;
    }

    void enqueue(int token) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add customer " << token << ".\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = token;
        cout << "Customer " << token << " arrived and enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No waiting customers to serve.\n";
            return;
        }
        cout << "Serving customer: " << arr[front++] << "\n";
    }

    void displayWaiting() const {
        if (isEmpty()) {
            cout << "No waiting customers.\n\n";
            return;
        }
        cout << "Waiting Customers (Front to Rear): ";
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n\n";
    }

    void displayCount() const {
        if (isEmpty()) {
            cout << "Number of waiting customers: 0\n\n";
        }
        else {
            cout << "Number of waiting customers: " << (rear - front + 1) << "\n\n";
        }
    }
};

int main() {
    BankQueue bank;

    bank.enqueue(101);
    bank.enqueue(102);
    bank.enqueue(103);

    bank.displayWaiting();
    bank.displayCount();

    bank.dequeue();

    bank.displayWaiting();
    bank.displayCount();

    return 0;
}