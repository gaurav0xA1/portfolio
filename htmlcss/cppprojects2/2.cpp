#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;

public:
    // Default Constructor
    Student() {
        roll = 0;
        name = "Unknown";
        cout << "Default constructor called.\n";
    }

    // Parameterized Constructor
    Student(int r, string n) {
        roll = r;
        name = n;
        cout << "Parameterized constructor called.\n";
    }

    // Copy Constructor
    Student(const Student &s) {
        roll = s.roll;
        name = s.name;
        cout << "Copy constructor called.\n";
    }

    // Function to display student data
    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }
};

int main() {
    // Object using Default Constructor
    Student s1;
    s1.display();

    // Object using Parameterized Constructor
    Student s2(101, "Alice");
    s2.display();

    // Object using Copy Constructor
    Student s3 = s2;
    s3.display();

    return 0;
}
