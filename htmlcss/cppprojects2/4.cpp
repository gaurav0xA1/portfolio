#include <iostream>
using namespace std;

class Demo {
private:
    int number;

public:
    // Constructor
    Demo(int n) {
        number = n;
        cout << "Constructor called. Number = " << number << endl;
    }

    // Destructor
    ~Demo() {
        cout << "Destructor called. Number = " << number << endl;
    }

    void display() {
        cout << "Value inside object: " << number << endl;
    }
};

int main() {
    Demo obj1(10); // Constructor will be called here
    obj1.display();

    {
        Demo obj2(20); // Constructor called
        obj2.display();
    } // obj2 goes out of scope here → Destructor called

    cout << "Back in main function.\n";

    return 0; // obj1 gets destroyed here → Destructor called
}
