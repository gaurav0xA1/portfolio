#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;

public:
    // Default Constructor
    Rectangle() {
        length = 0;
        breadth = 0;
        cout << "Default constructor called.\n";
    }

    // Parameterized Constructor (1 argument)
    Rectangle(int l) {
        length = l;
        breadth = l; // Assume square
        cout << "Single-parameter constructor called.\n";
    }

    // Parameterized Constructor (2 arguments)
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
        cout << "Two-parameter constructor called.\n";
    }

    void area() {
        cout << "Area = " << length * breadth << endl;
    }
};

int main() {
    // Using Default Constructor
    Rectangle r1;
    r1.area();

    // Using Single-Parameter Constructor
    Rectangle r2(5);
    r2.area();

    // Using Two-Parameter Constructor
    Rectangle r3(4, 6);
    r3.area();

    return 0;
}
