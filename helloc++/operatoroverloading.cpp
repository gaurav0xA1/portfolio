#include<iostream>

using namespace std;

class Complex{
    int real, imag;

    public:
        Complex(int r = 0 , int i = 0){
            real = r;
            imag = i;
        }

        void print(){
            cout<<real<<"+"<<imag<<"i"<<endl;
        }
};

int main(){
    int x=5;
    int y=4;
    int z=x;
    int z=x+y;
    cout<<"z value :"<<z<<endl;
}