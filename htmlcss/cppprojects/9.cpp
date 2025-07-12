// swap_by_ref_ptr.cpp
#include <iostream>
using namespace std;

void swapByRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByPtr(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swapByRef(x, y);
    cout << "After swapByRef: x=" << x << ", y=" << y << endl;

    swapByPtr(&x, &y);
    cout << "After swapByPtr: x=" << x << ", y=" << y << endl;

    return 0;
}
