#include <iostream>
using namespace std;
//#include <student1.cpp>
// Due to some errors, I can't perform line 3. But otherwise, I will be able to use classes from the file "student1.cpp"
class Student
{
public: // it's a access modifier
    int rollnumber;
    int age;
};

int main()
{
    // create objects statistically
    Student s1;
    Student s2, s3;

    s1.rollnumber = 24;
    s1.age = 18;

    cout << s1.rollnumber << endl;
    cout << s1.age << endl;

    s2.rollnumber = 101;

    //create objects dynamically
    Student *s4 = new Student;

    (*s4).age = 20;
    (*s4).rollnumber = 69;

    // Or (Both 29 and 30 are the same as 34 and 35)

    s4->age = 18;
    s4->rollnumber = 109;

    cout << s4->rollnumber << endl;
}