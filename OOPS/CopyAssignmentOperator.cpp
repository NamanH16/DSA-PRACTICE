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
    Student s1(10, 1001);

    Student s2(20, 2002);

    Student *s3 = new Student(30, 3001);

    s2 = s1; // s2 now has all vals same of s1

    *s3 = s1;
}