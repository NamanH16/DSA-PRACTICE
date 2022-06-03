#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;

    cout << sizeof(p) << endl; // pointers take 8 byte memory
    cout << i << endl;         //10
    cout << *p << endl;        //10 [dereferencing]

    i++;                //since i and *p are same,both their values will be affected
                        // Note: i and *p are same. Bas ek jagah pahuchne ke do raste hai
    cout << i << endl;  //11
    cout << *p << endl; //11

    int a = *p;
    a++;
    cout << a << endl;  //12
    cout << *p << endl; //11

    i = 12;
    cout << i << " " << *p << endl;
    *p = 23;
    cout << i << " " << *p << endl;

    (*p)++;
    cout << i << " " << *p << endl;

    return 0;
}