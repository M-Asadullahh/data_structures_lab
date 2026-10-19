#include <iostream>

using namespace std;

class CircularPacketQueue {
private:
    static const int CAPACITY = 5;
    int arr[CAPACITY];
    int front;
    int rear;
    int count;

public:
    CircularPacketQueue() {
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

    void enqueue(int packetID) {
        if (isFull()) {
            cout << "Queue Full! Packet " << packetID << " dropped.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % CAPACITY;
        }
        arr[rear] = packetID;
        count++;
        cout << "Packet " << packetID << " inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty! No packets to transmit.\n";
            return;
        }
        cout << "Transmitting oldest packet: " << arr[front] << "\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % CAPACITY;
        }
        count--;
    }

    void displayPackets() const {
        if (isEmpty()) {
            cout << "No packets waiting for transmission.\n\n";
            return;
        }
        cout << "Packets waiting for transmission: ";
        int index = front;
        for (int i = 0; i < count; ++i) {
            cout << arr[index] << " ";
            index = (index + 1) % CAPACITY;
        }
        cout << "\n\n";
    }
};

int main() {
    CircularPacketQueue networkBuffer;

    networkBuffer.enqueue(201);
    networkBuffer.enqueue(202);
    networkBuffer.enqueue(203);

    networkBuffer.displayPackets();

    networkBuffer.dequeue();

    networkBuffer.displayPackets();

    networkBuffer.enqueue(204);
    networkBuffer.enqueue(205);
    networkBuffer.enqueue(206);

    networkBuffer.displayPackets();

    return 0;
}