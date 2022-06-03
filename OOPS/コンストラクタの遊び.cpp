#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;

private:
    int age;

public:
    //Destructor
    ~Student()
    {
        cout << "Destructor called" << endl;
    }

    // Default constructor
    Student()
    {
        cout << "Constructor 1 called" << endl;
    }

    // Parameterized constructor
    Student(int rollNo)
    {
        cout << "Constructor 2 called" << endl;
        this->rollNo = rollNo;
    }

    Student(int a, int r)
    {
        cout << "Constructor 3 called" << endl;
        this->age = a;
        this->rollNo = r;
    }

    void display()
    {
        cout << age << " " << rollNo << endl;
    }
};

int main()
{
    Student s1; // constructor 1 called

    Student s2(101); // constructor 2 called

    Student s3(20, 111); // constructor 3 called

    Student s4(s3); // copy constructor

    s1 = s2; // (Copy assignment operator)no constructor called because they've been already created in memory

    Student s5 = s4; // copy constructor

    // rather than doing this in 2 lines
    // Student s5;
    // s5 = s4;
    // We can directly do something like line 57, as it's interpreted the same way in the memory,i.e., Student s5(s4);
}