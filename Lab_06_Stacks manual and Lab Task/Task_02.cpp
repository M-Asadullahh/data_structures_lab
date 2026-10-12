#include <iostream>
#include <string>

using namespace std;

class TextEditorUndoStack {
private:
    static const int MAX_SIZE = 100;
    string actions[MAX_SIZE];
    int top;

public:
    TextEditorUndoStack() {
        top = -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(const string& action) {
        if (isFull()) {
            cout << "Action stack is full!\n";
            return;
        }
        actions[++top] = action;
    }

    string pop() {
        if (isEmpty()) {
            cout << "No actions to undo!\n";
            return "";
        }
        return actions[top--];
    }

    string peek() const {
        if (isEmpty()) {
            return "No actions available";
        }
        return actions[top];
    }

    void displayActions() const {
        if (isEmpty()) {
            cout << "No actions stored.\n\n";
            return;
        }

        for (int i = top; i >= 0; --i) {
            cout << actions[i];
            if (i == top) {
                cout << "  <-- (TOP)";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main() {
    TextEditorUndoStack editor;

    editor.push("Type \"Hello\"");
    editor.push("Type \"World\"");
    editor.push("Add \"!\"");
    editor.push("Delete \"!\"");

    cout << "--- Initial Actions (TOP to Bottom) ---\n";
    editor.displayActions();

    cout << "Performing 1st Undo: " << editor.pop() << "\n";
    cout << "Performing 2nd Undo: " << editor.pop() << "\n\n";

    cout << "Current TOP Action: " << editor.peek() << "\n\n";

    cout << "--- Remaining Actions ---\n";
    editor.displayActions();

    return 0;
}