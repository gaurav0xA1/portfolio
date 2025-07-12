// io_manipulators.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159265358979;
    cout << "Default output: " << pi << endl;
    cout << fixed << setprecision(2);
    cout << "Fixed with 2 decimals: " << pi << endl;
    cout << setw(10) << setfill('*') << "Hello" << endl;
    return 0;
}
