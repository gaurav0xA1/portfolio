#include<iostream>
using namespace std;

class Complex 
{
public:
    int real, img;

    void getData()
    {
        cout << "Enter the values of real and imaginary: ";
        cin >> real >> img;
    }

    void display()
    {
        cout << real << " + " << img << "i" << endl;
    }
    Complex& addComplex(const Complex* c)
    {
        this->real += c->real;
        this->img += c->img;
        cout << "I am this pointer" << endl;
        return *this;
    }
};

int main()
{
    Complex c1, c2;
    c1.getData();
    c2.getData();

    c1.addComplex(&c2);
    cout << "Sum = ";
    c1.display();

    return 0;
}
