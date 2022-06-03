#include <iostream>
using namespace std;

// when dealing with const or reference variables,we need to initialize a const int beforehand only using "Initialization List"
class Student
{
public:
    int age;
    const int rollNo;
    int &x; // age reference variable

    Student(int r, int age) : rollNo(r), age(age), x(this->age)
    {
    }

    /*
    Also allowed:
    Student(int r) : rollNo(r) // Initialization List: at the pt of creation of "const int rollNo",we're saying to put the value of "r"
    {                          // something like "const int rollNo = r"
        //rollNo = r;
    }

    Student(int r,int age) : rollNo(r),age(age){

    }
    ---------------------------------------------------------------
    Student(int r)
    {
        rollNo = r; //rollNo has already been created in the memory beforehand with some random garbage value
                    // and now if I try to change it, it  will obviously give me error since rollNo is const
    }
*/
};

int main()
{
    Student s1(101, 20); // pass in roll number
    s1.age = 20;

    return 0;
}