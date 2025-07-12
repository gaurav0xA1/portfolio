#include <iostream>

using namespace std;
struct Employee
{
int id;
string name;
string address;
};
typedef struct Employee E;
void display(E emp)
{
    cout<<"My name is "<<emp.name<<endl;
}


int main(void){
    E emp;
    cout<<"Enter the id  of an employee:"<<endl;
    cin>>emp.id;
    cout<<"Enter the name of an employee"<<endl;
    cin>>emp.name;
    cout<<"Enter the address of an employee:"<<endl;
    cin>>emp.address;
    display(emp);

}