#include <iostream>
using namespace std;

class Minutes; // Forward declaration

class Hour
{
public:
    int hours;
    Hour(int hours = 0)
    {
        this->hours = hours;
    }
    // Conversion constructor
    Hour(const Minutes &m);

    void display()
    {
        cout << "Hours=" << hours << endl;
    }
};

class Minutes
{
public:
    int minutes;
    Minutes(int minutes)
    {
        this->minutes = minutes;
    }



    int getMinutes(){
        return minutes;
    }
};

Hour::Hour(const Minutes &m)
{
    hours = m.minutes / 60;
}

void display(){
    cout<<"Hours="<<hours<<endl;
}

int main()
{
    Hour h;
    Minutes m(324);
    h = m;
    h.display();
    return 0;
}
