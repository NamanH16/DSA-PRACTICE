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
    void display()
    {
        cout << age << " " << rollNo << endl;
    }

    int getAge()
    {
        return age;
    }
};

int main()
{
    Student s1;
    Student s2;

    s1.getAge();
    s1.rollNo = 101;

    s1.display();

    Student *s3 = new Student;

    s3->getAge();
    s3->rollNo = 122;

    s3->display();

    return 0;
}