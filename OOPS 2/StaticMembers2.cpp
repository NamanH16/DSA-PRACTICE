// totalStudents should increase by 1 every time I create a new object
// For this, constructor should be used since it's called everytime an object is called
#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;
    int age;

    static int totalStudents;

    Student()
    {
        totalStudents++;
    }
};

int Student ::totalStudents = 0;

int main()
{
    Student s1;
    Student s2;
    Student s3, s4, s5;

    cout << Student ::totalStudents << endl;

    return 0;
}

// Static basically means that a property belongs to a class and not object. That property won't be dependent on object.