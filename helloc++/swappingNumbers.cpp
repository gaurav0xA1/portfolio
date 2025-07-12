#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// void swap(int a, int b)
// {
//     a = a + b;
//     b = a - b;
//     a = a - b;
//     cout << "Inside value swap: a=" << a << ", b=" << b << endl;
// }

int main()
{
    int a = 2, b = 3;

    swap(&a, &b); // Pointer swap
    cout << "After pointer swap: a=" << a << ", b=" << b << endl;

    cout << "Before reference swap: a=" << a << ",b=" << b << endl;

    swap(a, b); // Reference swap
    cout << "After reference swap: a=" << a << ", b=" << b << endl;

    // swap(4, 5);      // Value swap, does not affect anything in main
}
