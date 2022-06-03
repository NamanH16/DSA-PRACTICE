#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    int age;
    char *name;

public:
    Student(int age, char *name)
    {
        this->age = age;
        // shallow copy : Line 14 would only store the address of the array, rather than the whole array,which should be avoided
        //this->name = name;

        //deep copy: Copying the whole array
        this->name = new char[strlen(name) + 1]; // +1 for null character
        strcpy(this->name, name);                // copying name in this->name
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

    name[2] = 'e';
    Student s2(22, name);
    s2.display();

    s1.display(); // this will give a different answer since we have only one array and s1,s2,name are calling on that one array

    return 0;
}