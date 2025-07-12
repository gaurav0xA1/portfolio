#include <iostream>
using namespace std;

// Forward declaration
class NPR;

class Dollar {
    float amount;
public:
    Dollar(float a = 0) {
        amount = a;
    }

    void display() {
        cout << "Dollar amount: $" << amount << endl;
    }

    // Conversion operator to convert Dollar to NPR
    operator NPR();
};

class NPR {
    float amount;
public:
    NPR(float a = 0) {
        amount = a;
    }

    void display() {
        cout << "Nepali Rupees amount: Ru " << amount << endl;
    }
};

// Definition of conversion operator
Dollar::operator NPR() {
    float rate = 133.5f; // Example rate: 1 USD = 133.5 NPR
    float nprAmount = amount * rate;
    return NPR(nprAmount);
}

int main() {
    float usd;
    cout << "Enter amount in Dollars: ";
    cin >> usd;

    Dollar d1(usd);
    d1.display();

    // Convert Dollar to NPR
    NPR n1 = d1; // Uses operator NPR() in Dollar
    n1.display();

    return 0;
}
