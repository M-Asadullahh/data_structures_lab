#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string memberName) {
        name = memberName;
        left = NULL;
        right = NULL;
    }
};

void showMember(Node* current) {
    if (current == NULL) {
        return;
    }

    cout << current->name << endl;

    cout << "   Left child  : ";
    if (current->left == NULL) {
        cout << "None" << endl;
    }
    else {
        cout << current->left->name << endl;
    }

    cout << "   Right child : ";
    if (current->right == NULL) {
        cout << "None" << endl;
    }
    else {
        cout << current->right->name << endl;
    }

    cout << endl;

    showMember(current->left);
    showMember(current->right);
}

int main() {
    Node* hod = new Node("Dr. Ahmed (HOD)");
    Node* coordinatorOne = new Node("Dr. Sara (Coordinator BSCS)");
    Node* coordinatorTwo = new Node("Dr. Bilal (Coordinator BSAI)");
    Node* facultyOne = new Node("Mr. Usman (Faculty)");
    Node* facultyTwo = new Node("Ms. Hina (Faculty)");
    Node* facultyThree = new Node("Mr. Kamran (Faculty)");
    Node* facultyFour = new Node("Ms. Zoya (Faculty)");

    hod->left = coordinatorOne;
    hod->right = coordinatorTwo;

    coordinatorOne->left = facultyOne;
    coordinatorOne->right = facultyTwo;

    coordinatorTwo->left = facultyThree;
    coordinatorTwo->right = facultyFour;

    cout << "University Department Hierarchy" << endl;
    cout << "-------------------------------" << endl;
    showMember(hod);

    return 0;
}