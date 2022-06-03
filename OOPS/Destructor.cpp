#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;

private:
    int age;

public:
    ~Student()
    {
        cout << "Destructor called" << endl;
    }

    Student(int rollNo)
    {
        cout << "Constructor 1 called" << endl;
        this->rollNo = rollNo;
    }

    Student(int a, int r)
    {
        cout << "Constructor 2 called" << endl;
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

    s2 = s1;  // destructor is called two times only and not 3 times
              // that's because object s3 is created dynamically in heap
    *s3 = s1; // when destructor is called
              // age and rollno of s1 and s2 is destroyed . But when we come over to s3, only it's address is present
    s2 = *s3; // so it's address got destroyed instead of the age and rollno

    // THEREFORE
    delete s3; // try commenting line 52, to see how destructor was called 2 times earlier
}