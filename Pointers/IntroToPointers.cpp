#include <iostream>
using namespace std;

int main()
{
    int i = 10; //even if I haven't assigned any value to i, storage will still be created for the variable i
    cout << &i << endl;
    int *p = &i; // here p is a pointer which can store the address of integers
    cout << p << endl;
    // With pointers, there're 2 ways of accessing the value stored in an integer
    // Going by the conventional way (cout<<i<<endl)
    // In this way, the value will be printed by first checking and then going to the address present in the symbol table
    // The second way is thru pointers. Since,we 've no need of checking the address,as the address of i has already been
    //stored in pointer p
    cout << *p << endl; // this operator is known as dereferencing operator

    float f = 10.2;
    float *pf = &f;

    double d = 89.12;
    double *pd = &d;

    return 0;
}