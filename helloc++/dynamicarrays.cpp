#include<iostream>

using namespace std;

int main (){
    int nstd;

    cout<<"Enter the number of students:"<<endl;
    cin>>nstd;
    int* students = new int [nstd];

    for(int i=0;i<nstd;i++){
        cout<<"Enter the marks of "<<i+1<<"nth student :"<<endl;
        cin>>students[i];
    }

    for(int i=0;i<nstd;i++){
        cout<<"The marks of "<<i+1<<"th student is :"<<students[i]<<endl;
    }

    delete[] students; //freee the dynamic array before program ends
    return 0;

}