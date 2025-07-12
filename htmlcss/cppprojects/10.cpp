// return_by_reference.cpp
#include <iostream>
using namespace std;

int& maxRef(int &a, int &b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 5, y = 10;
    cout << "Max before: " << maxRef(x, y) << endl;
    maxRef(x, y) = 100;  // Modify max variable directly
    cout << "x=" << x << ", y=" << y << endl;
    return 0;
}
