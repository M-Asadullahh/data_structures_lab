#include <iostream>
#include <string>

using namespace std;

class ImageNode {
public:
    string filename;
    ImageNode* prev;
    ImageNode* next;

    ImageNode(string name) {
        filename = name;
        prev = nullptr;
        next = nullptr;
    }
};

class ImageGallery {
private:
    ImageNode* head;
    ImageNode* tail;

public:
    ImageGallery() {
        head = nullptr;
        tail = nullptr;
    }

    void addImage(const string& name) {
        ImageNode* newNode = new ImageNode(name);
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
        if (head == nullptr) return;

        cout << "Image Gallery (First -> Last):\n";
        ImageNode* temp = head;
        int index = 1;
        while (temp != nullptr) {
            cout << index++ << ". " << temp->filename << "\n";
            temp = temp->next;
        }
        cout << "\n";
    }

    void displayBackward() const {
        if (tail == nullptr) return;

        cout << "Image Gallery (Last -> First):\n";
        ImageNode* temp = tail;
        int index = 1;
        while (temp != nullptr) {
            cout << index++ << ". " << temp->filename << "\n";
            temp = temp->prev;
        }
        cout << "\n";
    }

    void demonstrateNavigation() const {
        if (head == nullptr) return;

        cout << "--- Demonstrating Bidirectional Movement ---\n";
        ImageNode* current = head;
        cout << "Started at: " << current->filename << "\n";

        if (current->next != nullptr) {
            current = current->next;
            cout << "Moved forward (next) to: " << current->filename << "\n";
        }

        if (current->next != nullptr) {
            current = current->next;
            cout << "Moved forward (next) to: " << current->filename << "\n";
        }

        if (current->prev != nullptr) {
            current = current->prev;
            cout << "Moved backward (prev) to: " << current->filename << "\n";
        }
        cout << "\n";
    }

    ~ImageGallery() {
        ImageNode* current = head;
        while (current != nullptr) {
            ImageNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    ImageGallery gallery;

    gallery.addImage("sunset.jpg");
    gallery.addImage("mountains.png");
    gallery.addImage("ocean_view.jpeg");
    gallery.addImage("forest_path.jpg");
    gallery.addImage("city_skyline.png");

    gallery.displayForward();
    gallery.displayBackward();
    gallery.demonstrateNavigation();

    return 0;
}