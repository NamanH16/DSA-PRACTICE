// What if I want the object s2 to have the same properties of object s1?
// One simple way is s2.age = s1.age
// But we don't need to do it explicitly,since we have the copy constructor
#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;

private:
    int age;

public:
    Student(int a, int r)
    {
        cout << "Constructor called" << endl;
        age = a;
        rollNo = r;
    }

    void display()
    {
        cout << age << " " << rollNo << endl;
    }
};

int main()
{
    Student s1(18, 1001);
    cout << "S1: ";
    s1.display();

    Student s2(s1); // copy constructor: Just pass in s1 as argument
    cout << "S2: ";
    s2.display();

    Student *s3 = new Student(20, 2001);
    cout << "S3: ";
    s3->display();

    Student s4(*s3);

    Student *s5 = new Student(*s3);
    Student *s6 = new Student(s1);

    return 0;
}