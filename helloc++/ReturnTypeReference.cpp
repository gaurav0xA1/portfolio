#include <iostream>

using namespace std;

int &function(int &a)
{
    cout<<"memory locaton :"<<&a<<endl;
    return a;
}

int main(void)
{
    int a;
    cout << "Enter the value of a" << endl;
    cin>>a;
    cout<<function(a)<<endl;
    cout<<"Meory location :"<<&a<<endl;
}