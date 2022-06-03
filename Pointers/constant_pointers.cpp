#include <iostream>
using namespace std;

int main()
{
    int const i = 10;

    //int *p = &i;[ERROR!]  we cannot store the address of 'const int' inside a normal pointer

    int const *p = &i; // in order to understand it, always read it backwards {p is a pointer to a const int}
    // by creating a const pointer, p has promised that it won't be able to edit const int i

    int j = 12;
    const int *p2 = &j;

    cout << *p2 << endl;
    j++;
    cout << *p2 << endl;

    return 0;
}