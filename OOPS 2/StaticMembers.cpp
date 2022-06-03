#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo; // rollNo and age are non-static by default
    int age;

    static int TotalStudents; // Note that the value of TotalStudents will not change even tho rollNo and age keep on changing
    // Static members: belong to a class but a copy isn't created for every object
};

// Static members can't be initialized within the function

int Student ::TotalStudents = 20; // data type, class name,scope resolution opr,static property

int main()
{
    Student s1; // s1 will have copy of class Student with rollNo and age(but not TotalStudents, it will remain with class itself)

    // Now what if I want to print TotalStudents?
    // Should I write something like s1.TotalStudents() ??
    // Absolutely NOT!! Since s1 only has rollNo and age, TotalStudents is still present in class Student

    // It can be printed in the following way:
    cout << Student ::TotalStudents << endl; // static members are accessed by"Class Name, Scope Resolution Operator(::) and the static property

    cout << s1.rollNo << " " << s1.age << endl;

    return 0;
}