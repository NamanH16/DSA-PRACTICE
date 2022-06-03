#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int j = 21;

    int const *p = &i; // this doesn't mean that 'p' itself is const, but is promising that it won't change 'i'
    // p is a pointer to const int
    // (*p)++ [ERROR!!] since it'll break its promise of not effecting i
    p = &j;

    int *const p2 = &i;
    // p2 is a constant pointer to an integer
    (*p2)++;
    //p2 = &j; [ERROR!!] We can't do this since p2 is constant

    int const *const p3 = &i; // this is possible as well
    // p3 is a constant pointer to a const int
    // we can neither change p3 nor i
    //(*p3)++ and p3 = &j both are invalid

    return 0;
}