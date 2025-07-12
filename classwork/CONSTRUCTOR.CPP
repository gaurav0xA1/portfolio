#include<iostream>

using namespace std;
class Shape{
    public:
        int length,breadth;//instance variables
        Shape(){//default constructor
            length=0;
            breadth=0;
            }
            int area(){
                return length*breadth;
            }
};

int main(void)
{
    Shape noshape; //object->calls default constructor
    cout<<"Area of noshape="<<noshape.area()<<endl;
}

//constructor : It is a function having same name as class name.It is used to create objects of a class.
//  Mainly it is used to initialize the instance variables. There are basically three types of construcopy constructor (default and userdefined)
//Constructors are called when objects are created.
//Memory allocation is done via constructors for objects.
