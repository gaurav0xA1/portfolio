// function_overloading.cpp
#include <iostream>
using namespace std;

double area(double radius) { return 3.1416 * radius * radius; }
int area(int side) { return side * side; }
double area(double length, double width) { return length * width; }

int main() {
    cout << "Area of circle (r=5): " << area(5.0) << endl;
    cout << "Area of square (side=4): " << area(4) << endl;
    cout << "Area of rectangle (l=5, w=3): " << area(5.0, 3.0) << endl;
    return 0;
}
