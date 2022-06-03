// Pointer Arithmetic
#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;

    cout << p << endl;
    p += 2;
    cout << p << endl;

    cout << p << endl;
    p -= 2;
    cout << p << endl;

    double d = 102.3;
    double *ptr = &d;
    cout << ptr << endl;
    ptr++; // double takes 8 bytes
    cout << ptr << endl;

    return 0;
}