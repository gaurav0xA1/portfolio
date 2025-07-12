#include<iostream>
using namespace std;

// Function prototype with parameters
int euclidean(int a, int b);

int main()
{   
    int a, b;
    cout << "Enter two numbers [FORMAT gcd(x,y)] :" << endl;
    cin >> a >> b;

    int result = euclidean(a, b); // call and store the return value
    cout << "GCD is : " << result << endl;

    return 0;
}

int euclidean(int a , int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a; // return the final GCD
}
