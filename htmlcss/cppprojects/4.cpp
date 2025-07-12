// dynamic_memory.cpp
#include <iostream>
using namespace std;

int main() {
    int *arr = new int[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    cout << "You entered: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;  // Free memory
    return 0;
}
