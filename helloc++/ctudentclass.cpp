#include<iostream>
#include<string>

using namespace std;

class Student{

private :
    string name;
    string rollNo;
    int marks;

public:
    Student(string studentName, string studentRollNo, int sstudentMarks){
        name = studentName;
        rollNo = studentRollNo;
        marks = sstudentMarks;
    }
//method to calculate grade
    char calculateGrade(){
        if (marks>=90) return 'A';
        else if(marks>=80) return'B';
        else if(marks>=70) return'C';
        else if(marks>=60) return'D';
        else if(marks>=50) return'E';
        else return 'F';

    }
//method to display student information
    void displayInfo() {
        cout<<"Student:"<<name<<"(Roll No. : "<<rollNo
        <<"),Marks:" <<marks <<",Grade:"<<calculateGrade() << endl;
        
    }
};

int main(){
    //create student objects

    Student student1("Alic1e Johnson","S001",815);
    Student student2("Ali2ce Johnson","S002",852);
    Student student3("Al3ice Johnson","S003",853);

    //display student information

    student1.displayInfo();
    student2.displayInfo();
    student3.displayInfo();

    return 0;


}