#include <iostream>
using namespace std;

class Student
{
    static int totalStudents;

public:
    int rollNo;
    int age;

    Student()
    {
        totalStudents++;
    }

    int getRollNo()
    {
        return rollNo;
    }

    static int getTotalStudents() // if static member is  private, then make its getter function static as well.
    {                             // static functions can only access static members/function only
        return totalStudents;     // Also, "this" keyword isn't accessible by static members/functions
    }
};

int Student ::totalStudents = 0;

int main()
{
    Student s1;
    Student s2;
    Student s3, s4, s5;

    cout << Student::getTotalStudents() << endl;

    return 0;
}