// dynamic_sort.cpp
#include <iostream>
using namespace std;

int main() {
    int *arr = new int[10];
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++) cin >> arr[i];

    // Simple Bubble Sort
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted integers: ";
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    delete[] arr;
    return 0;
}
