#include <iostream>
using namespace std;

// Forward declaration
class Feet;

class Inches {
    float inch;
public:
    Inches(float i = 0) {
        inch = i;
    }

    void display() {
        cout << "Inches: " << inch << endl;
    }

    // Conversion operator to convert Inches to Feet
    operator Feet();
};

class Feet {
    int feet;
    float inches;
public:
    Feet(int f = 0, float i = 0) {
        feet = f;
        inches = i;
    }

    void display() {
        cout << "Feet: " << feet << ", Inches: " << inches << endl;
    }
};

// Definition of conversion operator
Inches::operator Feet() {
    int f = int(inch / 12);
    float in = inch - (f * 12);
    return Feet(f, in);
}

int main() {
    float len;
    cout << "Enter length in inches: ";
    cin >> len;

    Inches i1(len);
    i1.display();

    // Convert Inches to Feet
    Feet f1 = i1; // Uses operator Feet() in Inches
    f1.display();

    return 0;
}
