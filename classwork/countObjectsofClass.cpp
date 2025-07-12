#include<iostream>

using namespace std;

class Student
{
    public:
        static int count;

        Student()
        {
            // Constructor called when object is created
            count++;
        }

        int getCount();
};

int Student::count = 0;

int Student::getCount()
{
    return count;
}

int main(void)
{
    Student s1; // constructor is called
    Student s2; // constructor is called
    Student s3; // constructor is called
    cout << "No of objects = " << s3.getCount() << endl;

    return 0;
}
