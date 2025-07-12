#include <iostream>
using namespace std;

// Function to convert a single character (via pointer) to uppercase
void toCapital(char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - 32; // or *c = toupper(*c); for better clarity
    }
}

// Function to convert an entire string to uppercase
void toCapital(string &s) {
    for (int i = 0; i < s.length(); ++i) {
        toCapital(&s[i]);
    }
}

int main() {
    string str = "hello world!";
    toCapital(str);
    cout << str << endl; // Output: HELLO WORLD!
    return 0;
}