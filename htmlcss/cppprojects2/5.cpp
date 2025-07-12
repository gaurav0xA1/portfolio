#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;

public:
    // Constructor
    Student(int r, string n) {
        roll = r;
        name = n;
    }

    // Function to display data
    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }

    // --- a. Pass Object by Value ---
    void showByValue(Student s) {
        cout << "Passed by Value:\n";
        s.display();
    }

    // --- b. Pass Object by Reference ---
    void showByReference(Student &s) {
        cout << "Passed by Reference:\n";
        s.display();
    }

    // --- c. Pass Object by Pointer ---
    void showByPointer(Student *s) {
        cout << "Passed by Pointer:\n";
        s->display();
    }
};

int main() {
    Student s1(101, "Alice");
    Student s2(102, "Bob");

    cout << "--- Original Object ---\n";
    s1.display();

    cout << "\n--- Passing Object by Value ---\n";
    s1.showByValue(s2); // Copy is made

    cout << "\n--- Passing Object by Reference ---\n";
    s1.showByReference(s2); // No copy

    cout << "\n--- Passing Object by Pointer ---\n";
    s1.showByPointer(&s2); // Pointer is passed

    return 0;
}
