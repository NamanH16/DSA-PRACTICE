#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;

private:
    int age;

public:
    void display()
    {
        cout << age << " " << rollNo << endl;
    }

    Student(int a, int r)
    {
        cout << "this: " << this << endl; // 'this' keyword basically holds the address of the current object
        cout << "Constructor called" << endl;
        this->age = a; // here ,'this' isn't mandatory,since we know we're talking about age and rollno of particular object
        this->rollNo = r;
    }

    Student(int rollNo)
    {
        cout << "Constructor 2 called" << endl;

        this->rollNo = rollNo; // Here,'this' is mandatory in order to specify that I am putting value of rollNo in rollNo
    }
};

int main()
{
    Student s1(18, 101);
    cout << "Address of s1 memory block: " << &s1 << endl;

    Student s2(20);
    s2.display();
}