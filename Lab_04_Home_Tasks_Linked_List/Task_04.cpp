#include <iostream>
#include <string>

using namespace std;

struct CourseNode {
    string courseCode;
    string courseName;
    int creditHours;
    CourseNode* next;
};

void addAtBeginning(CourseNode*& head) {
    string code, name;
    int credits;
    cout << "Enter Course Code: ";
    cin >> code;
    cout << "Enter Course Name: ";
    cin >> name;
    cout << "Enter Credit Hours: ";
    cin >> credits;

    CourseNode* temp = new CourseNode();
    temp->courseCode = code;
    temp->courseName = name;
    temp->creditHours = credits;
    temp->next = head;
    head = temp;

    cout << "Course added at the beginning.\n";
}

void addAtEnd(CourseNode*& head) {
    string code, name;
    int credits;
    cout << "Enter Course Code: ";
    cin >> code;
    cout << "Enter Course Name: ";
    cin >> name;
    cout << "Enter Credit Hours: ";
    cin >> credits;

    CourseNode* temp = new CourseNode();
    temp->courseCode = code;
    temp->courseName = name;
    temp->creditHours = credits;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    }
    else {
        CourseNode* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    cout << "Course added at the end.\n";
}

void searchCourse(CourseNode* head) {
    if (head == NULL) {
        cout << "Course list is empty.\n";
        return;
    }

    string searchCode;
    cout << "Enter Course Code to Search: ";
    cin >> searchCode;

    CourseNode* curr = head;
    bool found = false;

    while (curr != NULL) {
        if (curr->courseCode == searchCode) {
            cout << "Course Found: Code = " << curr->courseCode << ", Name = " << curr->courseName << ", Credits = " << curr->creditHours << "\n";
            found = true;
            break;
        }
        curr = curr->next;
    }

    if (!found) {
        cout << "Course not found.\n";
    }
}

void deleteCourse(CourseNode*& head) {
    if (head == NULL) {
        cout << "Course list is empty.\n";
        return;
    }

    string delCode;
    cout << "Enter Course Code to Delete: ";
    cin >> delCode;

    if (head->courseCode == delCode) {
        CourseNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Course deleted successfully.\n";
        return;
    }

    CourseNode* prev = head;
    CourseNode* curr = head->next;
    bool found = false;

    while (curr != NULL) {
        if (curr->courseCode == delCode) {
            found = true;
            prev->next = curr->next;
            delete curr;
            cout << "Course deleted successfully.\n";
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (!found) {
        cout << "Course not found.\n";
    }
}

void displayList(CourseNode* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    CourseNode* p = head;
    while (p != NULL) {
        cout << p->courseCode;
        if (p->next != NULL) {
            cout << " -> ";
        }
        p = p->next;
    }
    cout << "\n";
}

void countCourses(CourseNode* head) {
    int total = 0;
    CourseNode* ptr = head;
    while (ptr != NULL) {
        total++;
        ptr = ptr->next;
    }
    cout << "Total number of courses: " << total << "\n";
}

void concatenateLists(CourseNode*& list1, CourseNode*& list2) {
    if (list1 == NULL) {
        list1 = list2;
    }
    else {
        CourseNode* temp = list1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = list2;
    }
    list2 = NULL;
    cout << "Lists concatenated successfully.\n";
}

int main() {
    CourseNode* morningList = NULL;
    CourseNode* eveningList = NULL;

    int activeListChoice = 1;
    int opt;

    while (true) {
        cout << "\n=== Course Management System ===\n";
        cout << "Active List: " << (activeListChoice == 1 ? "Morning Courses" : "Evening Courses") << "\n";
        cout << "1. Add Course at Beginning\n";
        cout << "2. Add Course at End\n";
        cout << "3. Search Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Display All Courses\n";
        cout << "6. Count Total Courses\n";
        cout << "7. Switch Active List (Morning/Evening)\n";
        cout << "8. Concatenate Evening List into Morning List\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> opt;

        CourseNode*& currentHead = (activeListChoice == 1) ? morningList : eveningList;

        if (opt == 1) {
            addAtBeginning(currentHead);
        }
        else if (opt == 2) {
            addAtEnd(currentHead);
        }
        else if (opt == 3) {
            searchCourse(currentHead);
        }
        else if (opt == 4) {
            deleteCourse(currentHead);
        }
        else if (opt == 5) {
            cout << "\n--- Displaying Courses ---\n";
            displayList(currentHead);
        }
        else if (opt == 6) {
            countCourses(currentHead);
        }
        else if (opt == 7) {
            if (activeListChoice == 1) {
                activeListChoice = 2;
            }
            else {
                activeListChoice = 1;
            }
            cout << "Switched to " << (activeListChoice == 1 ? "Morning Courses" : "Evening Courses") << " list.\n";
        }
        else if (opt == 8) {
            cout << "\nMorning Courses before concatenation:\n";
            displayList(morningList);
            cout << "Evening Courses before concatenation:\n";
            displayList(eveningList);

            concatenateLists(morningList, eveningList);

            cout << "\nCombined Course List:\n";
            displayList(morningList);

            activeListChoice = 1;
        }
        else if (opt == 9) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}