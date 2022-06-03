// First go thru the whole program and then read:
// This makes us wonder why do we even need private functions when we can set it anyways.
// But this actually is really useful since nobody would be able to directly manipulate it.
// Eg:
/*
void setAge(int a,int password)
{
    if(password != 123){    // we can set a password so that only limited people can access it 
        return;
    }
    if(a < 0 ){              //age should be striclty positive
        return;
    }
    age = a;
}*/
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

    void setAge(int a)
    {
        age = a;
    }
};

int main()
{
    Student s1;

    Student *s2 = new Student;

    s1.setAge(20);
    s2->setAge(18);

    s1.rollNo = 101;
    s2->rollNo = 123;

    s1.display();
    s2->display();

    return 0;
}