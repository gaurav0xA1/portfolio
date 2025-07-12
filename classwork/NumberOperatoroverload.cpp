#include<iostream>
using namespace std;

class Number {
    int data;

public:
    void setData(int value) {
        data = value;
    }

    void add(Number nob) {
        data = data + nob.data;
    }

    void display() {
        cout << "The value is: " << data << endl;
    }
};

int main() {
    Number n1, n2;

    n1.setData(10);
    n2.setData(20);

    n1.add(n2);
    n1.display(); // Should output 30

    return 0;
}
