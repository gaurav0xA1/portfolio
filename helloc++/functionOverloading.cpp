#include <iostream>

using namespace std;

// function overloading: same function is overloaded on the basis of
// 1. different number of parameters
// 2. different data types of parameters

int area(int);           // Square
int area(int, int);      // Rectangle
double area(double);     // Circle (assuming radius is passed)

// int main(void)
// {
//     int l,b;
//     double r;
//     cout<<"Enter the values of l,b and r"<<endl;
//     cin>>l>>b>>r;
//     cout<<"Area of circle = "<<area(r)<<endl;
//     cout<<"Area of Rectangle = "<<area(l,b)<<endl;
//     cout<<"Area of Square = "<<area(l)<<endl;
// }

int area(int l) {        // Square
    return l * l;
}

int area(int l, int b) { // Rectangle
    return l * b;
}

double area(double r) {  // Circle
    return 3.14159 * r * r;
}

int main() {
    int l = 5, b = 6;
    double r = 4.5;

    cout << "Area of square: " << area(l) << endl;
    cout << "Area of rectangle: " << area(l, b) << endl;
    cout << "Area of circle: " << area(r) << endl;

    return 0;
}
