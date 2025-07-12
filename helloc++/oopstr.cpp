#include<iostream>//header file

using namespace std;//using std library
class MathOperation{//class defination
    public:
        const float PI=3.14;//member variable
        int factorial(int n)//member function
        {
            if(n==0||n==1){
                return 1;
            }
            return n*factorial(n-1);
        }
};//classdefinationclosed
int main(void){
    MathOperation mop;//object of a class
    int num;
    cout<<"Enter the value of num:"<<endl;
    cin>>num;
    cout<<"The factorial of "<<num<<" = "<<mop.factorial(num)<<endl;
}//main function