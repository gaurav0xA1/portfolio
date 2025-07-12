// input_methods.cpp
#include <iostream>
using namespace std;

int main() {
    char buffer1[50], buffer2[50], buffer3[50];

    cout << "Enter name using cin: ";
    cin >> buffer1;
    cin.ignore();  // Clear newline

    cout << "Enter a full line using getline(cin, chararray): ";
    cin.getline(buffer2, 50);

    cout << "Enter a line using cin.getline(chararray, size): ";
    cin.getline(buffer3, 50);

    cout << "\nYou entered (cin): " << buffer1 << endl;
    cout << "You entered (getline): " << buffer2 << endl;
    cout << "You entered (cin.getline): " << buffer3 << endl;

    return 0;
}
