#include <iostream>
#include <string>

using namespace std;

class BrowserStack {
private:
    static const int MAX_SIZE = 100;
    string stack[MAX_SIZE];
    int top;

public:
    BrowserStack() {
        top = -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(const string& page) {
        if (isFull()) {
            cout << "History Full!\n";
            return;
        }
        stack[++top] = page;
    }

    string pop() {
        if (isEmpty()) {
            cout << "No History to Go Back!\n";
            return "";
        }
        return stack[top--];
    }

    string peek() const {
        if (isEmpty()) {
            return "No Active Page";
        }
        return stack[top];
    }

    void displayHistory() const {
        if (isEmpty()) {
            cout << "Browsing History is empty.\n\n";
            return;
        }

        cout << "--- Browsing History (TOP to Bottom) ---\n";
        for (int i = top; i >= 0; --i) {
            cout << stack[i];
            if (i == top) {
                cout << "  <-- (Current Page)";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main() {
    BrowserStack history;

    history.push("Google");
    history.push("YouTube");
    history.push("Facebook");
    history.push("GitHub");

    history.displayHistory();

    cout << "Simulating Back button (Popped page): " << history.pop() << "\n\n";

    cout << "Current TOP Page: " << history.peek() << "\n\n";

    cout << "--- Remaining Browsing History ---\n";
    history.displayHistory();

    return 0;
}