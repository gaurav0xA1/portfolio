#include<iostream>

using namespace std;

void counter(){
    
    static int count=-0;
    cout<<"Counter ="<<++count<<endl;
}

int main(){
    counter();
    counter();
    counter();
}