#include <iostream>
using namespace std;

// Define the Employee class
class Employee {
private:
    int id;
    string name;
    float salary;

public:
    // Function to input employee details
    void inputDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(); // Clear input buffer

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void displayDetails() {
        cout << "\nEmployee ID: " << id;
        cout << "\nEmployee Name: " << name;
        cout << "\nEmployee Salary: $" << salary << "\n";
    }
};

int main() {
    // Create an array of 3 Employee objects
    Employee emp[3];

    // Input and display details for 3 employees
    for (int i = 0; i < 3; i++) {
        cout << "\nEnter details for Employee " << i + 1 << ":\n";
        emp[i].inputDetails();
    }

    cout << "\n--- Employee Information ---\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nDetails of Employee " << i + 1 << ":";
        emp[i].displayDetails();
    }

    return 0;
}
