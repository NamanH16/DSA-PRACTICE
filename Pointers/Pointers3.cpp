// Arrays and Pointers
#include <iostream>
using namespace std;

int main()
{
    int a[10];
    cout << a << endl;     //prints the address of the array
    cout << &a[0] << endl; // a[0] can also said to be the address of the first element of the array,i.e. a[0]

    a[0] = 5;
    a[1] = 10;

    cout << a << endl;
    cout << a + 1 << endl; // prints the address of a[1](the 2nd element)

    cout << *a << endl;
    cout << *(a + 1) << endl; // *(a+1)->a[1]   therefore *(a+i)->a[i]

    int *p = &a[0];

    cout << p << endl;
    cout << a << endl;

    // NOTE: The address of arrays can never be reassigned
    // U can't do something like a += 3
    // Though u may p = a
    cout << &p << endl; //gives the address of where the pointer is stored in the memory
    cout << &a << endl;

    cout << sizeof(p) << endl;
    cout << sizeof(a) << endl;

    p = p + 1;
    p = a + 1;
    //a = a+1 ERROR!!

    return 0;
}