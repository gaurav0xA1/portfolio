#include <iostream>
#include <string> // For getline(cin, string) - though we won't use it in this example
#include<limits>
using namespace std;

int main() {
    const int SIZE = 100;
    char charArray1[SIZE];
    char charArray2[SIZE];
    char charArray3[SIZE];
    
    cout << "Demonstrating the differences between input methods:\n\n";
    
    // 1. Using cin >>
    cout << "1. Using cin >> (enter 'Hello World'): ";
    cin >> charArray1;
    cout << "   cin >> stored: " << charArray1 << "\n\n";
    
    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // 2. Using getline(cin, charArray) - Note: This is actually not standard C++
    // The standard getline works with string objects, not char arrays
    // This demonstrates what might happen if someone tries to use getline incorrectly
    cout << "2. Attempting to use getline(cin, charArray) (enter 'Hello World'): ";
    // This line would normally cause a compilation error in standard C++
    // getline(cin, charArray2); // Not standard - commented out
    
    // Instead, we'll show the proper way using cin.getline()
    cout << "   Note: Standard getline() works with string objects, not char arrays.\n";
    cout << "   For char arrays, we use cin.getline().\n\n";
    
    // 3. Using cin.getline(charArray, size)
    cout << "3. Using cin.getline(charArray, size) (enter 'Hello World'): ";
    cin.getline(charArray3, SIZE);
    cout << "   cin.getline() stored: " << charArray3 << "\n\n";
    
    // Let's demonstrate the difference in handling whitespace
    cout << "Let's demonstrate how these methods handle whitespace differently...\n\n";
    
    char anotherArray[SIZE];
    
    cout << "Enter a sentence with spaces (e.g., 'C++ Programming'):\n";
    
    // Using cin >>
    cout << "Using cin >> : ";
    cin >> anotherArray;
    cout << "   Stored: " << anotherArray << "\n";
    
    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Using cin.getline()
    cout << "Using cin.getline() : ";
    cin.getline(anotherArray, SIZE);
    cout << "   Stored: " << anotherArray << "\n";
    
    return 0;
}