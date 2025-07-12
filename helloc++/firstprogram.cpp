#include<iostream>
int factorial(int);
using namespace std;

int main(void){
    int n;
    cout<<"Hello Semester Two" << endl;
    cin>>n;
    cout<<factorial(n) << endl;
}
int factorial(int n)
{
    if (n==0||n==1)
        return 1;
    return n*factorial(n-1);
}
