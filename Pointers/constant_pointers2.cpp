// Don't run it, it's full of errors!!
#include <iostream>
using namespace std;

void g(const int &a) //this function basically promises that it won't mess up with your value
{
    a++; // it's not a modifiable value
} // will give error

void f(const int *p) // if it would've been 'int *p' then *p++ would've changed the value of j as well,
//but since I didn't want them to change it, I passed an constant pointer
{
    (*p)++; // will give an error
}

int main()
{
    int j = 12;
    int *p = &j;
    f(p); // or I could've passed '&j' as well(both are same) -> f(&j)
    g(j);

    cout << j << endl;

    return 0;
}