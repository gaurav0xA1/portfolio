#include <iostream>

using namespace std;

int main ()
{
    int rows,cols;
    cout<<"Enter the number of rows:"<<endl;
    cin>>rows;
    cout<<"Enter thenumber of cloumns:"<<endl;
    cin>>cols;

    int** matrix;
    matrix = new int*[rows];

    for(int i=0;i<rows;i++)
        matrix[i] = new int[cols];
    
    
}