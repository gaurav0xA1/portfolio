#include <iostream>
#include <vector>
using namespace std;

void findPrimes(int n) {
    vector<bool> isPrime(n + 1, true); // Initially assume all are primes
    isPrime[0] = isPrime[1] = false;   // 0 and 1 are not primes

    // Sieve of Eratosthenes algorithm
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            // Mark all multiples of p as non-prime
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Print all prime numbers
    cout << "Prime numbers between 1 and " << n << ":\n";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int limit = 100;
    findPrimes(limit);
    return 0;
}