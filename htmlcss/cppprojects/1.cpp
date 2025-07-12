// prime_numbers.cpp
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    cout << "Prime numbers from 1 to 100 are: ";
    for (int i = 1; i <= 100; i++) {
        if (isPrime(i)) cout << i << " ";
    }
    cout << endl;
    return 0;
}
