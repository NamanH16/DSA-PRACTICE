// NOTE: Whenever we have a string in our class, always create your own copy constructor to avoid shallow copy
#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    int age;

public:
    char *name;

    Student(int age, char *name)
    {
        this->age = age;
        // shallow copy
        //this->name = name;

        //deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Copy constructor
    // we needed to pass 's' by reference since we are now unable to access the in-built copy constructor
    //and therefore we need to pass by ref sine it's our personal copy constructor
    // Why const? Because we want to avoid any illegal expressions
    // Eg, what if someone just writes at the end of the copy constructor,s.age= -1?
    // Our constructor would be ruined/
    Student(Student const &s)
    {
        // shallow copy
        //this->age = s.age;
        //this->name = s.name;

        //deep copy
        this->age = s.age;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    char name[] = "abcd";

    Student s1(18, name);
    s1.display();

    Student s2(s1);

    s2.name[0] = 'x';

    s1.display();
    s2.display();

    return 0;
}