//Double pointers : Basically they're pointers which store the address of other pointers
#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;

    int **p2 = &p;

    cout << &p << endl; // Both lines 12 and 13 give the same output
    cout << p2 << endl;

    cout << p << endl; // All 3 lines 15,16 and 17 give the same output
    cout << *p2 << endl;
    cout << &i << endl;

    cout << i << endl; // All 3 lines 19,20 and 21 give the same output
    cout << *p << endl;
    cout << **p2 << endl;

    return 0;
}
