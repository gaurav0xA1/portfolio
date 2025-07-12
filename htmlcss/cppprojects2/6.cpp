#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v = 0) {
        value = v;
    }

    // Display function
    void display() {
        cout << "Value: " << value << endl;
    }

    // --- a. Return object as reference ---
    static Number& getLarger(Number &a, Number &b) {
        return (a.value > b.value) ? a : b;
    }

    // --- b. Return object as pointer ---
    static Number* getSmaller(Number *a, Number *b) {
        return (a->value < b->value) ? a : b;
    }
};

int main() {
    Number n1(10), n2(25);

    cout << "--- Returning Object as Reference ---" << endl;
    Number &larger = Number::getLarger(n1, n2);
    larger.display();

    cout << "\n--- Returning Object as Pointer ---" << endl;
    Number *smaller = Number::getSmaller(&n1, &n2);
    smaller->display();

    return 0;
}
