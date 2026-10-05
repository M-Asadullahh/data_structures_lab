#include <iostream>
#include <string>

class Node {
public:
    std::string url;
    Node* prev;
    Node* next;

    Node(std::string website) {
        url = website;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory() {
        head = nullptr;
        tail = nullptr;
    }

    void visitWebsite(const std::string& url) {
        Node* newNode = new Node(url);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() const {
        if (head == nullptr) {
            std::cout << "Browser history is empty.\n";
            return;
        }

        std::cout << "Browser History (First -> Last):\n";
        Node* temp = head;
        int step = 1;
        while (temp != nullptr) {
            std::cout << step++ << ". " << temp->url << "\n";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void displayBackward() const {
        if (tail == nullptr) {
            std::cout << "Browser history is empty.\n";
            return;
        }

        std::cout << "Browser History (Last -> First):\n";
        Node* temp = tail;
        int step = 1;
        while (temp != nullptr) {
            std::cout << step++ << ". " << temp->url << "\n";
            temp = temp->prev;
        }
        std::cout << "\n";
    }
    ~BrowserHistory() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    BrowserHistory history;

    history.visitWebsite("google.com");
    history.visitWebsite("github.com");
    history.visitWebsite("au.edu.pk");
    history.visitWebsite("stackoverflow.com");
    history.visitWebsite("youtube.com");

    history.displayForward();

    history.displayBackward();

    return 0;
}