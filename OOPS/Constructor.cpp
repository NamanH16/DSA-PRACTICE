#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;

private:
    int age;

    // Even though age is private, note that private can still be accessed if it's within the class
public:
    // Default constructor
    Student()
    {
        cout << "Constructor called" << endl;
    }

    // Parameterized constructor
    Student(int r)
    {
        cout << "Constructor 2 called" << endl;
        rollNo = r;
    }

    Student(int a, int r)
    {
        cout << "Constructor 3 called" << endl;
        age = a;
        rollNo = r;
    }

    void display()
    {
        cout << age << " " << rollNo << endl;
    }

    void setAge(int a, int password)
    {
        if (password != 123)
        { // we can set a password so that only limited people can access it
            return;
        }
        if (a < 0)
        { //age should be striclty positive
            return;
        }
        age = a;
    }
};

int main()
{
    // For one object only one constructor can be called : either default or parameterized
    Student s1;

    s1.display();

    Student s2;

    Student *s3 = new Student;
    s3->display();

    cout << "Parameterized Constructors Demo" << endl;
    Student s4(10);

    s4.display();

    Student *s5 = new Student(101);
    s5->display();

    Student s6(18, 110);
    s6.display();
}