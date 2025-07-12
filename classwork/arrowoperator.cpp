#include <iostream>

using namespace std;

class oneClass
{
    public:
        void print()
        {
            cout<<"I am  from One class"<< endl;
        }
};

class AnotherClass
{
    private:
        oneClass *ptr;

    public:
        //AnotherClass(MyData *p) : ptr(p) {} , we can initialize
        AnotherClass(oneClass *p)
        {
            ptr = p;
        }

        oneClass *operator->()
        {
            return ptr;
        }
};


int  main()
{
    oneClass *data = new oneClass();
    AnotherClass aptr(data);
    aptr->print(); // Calls print() through the overloaded - 
}
