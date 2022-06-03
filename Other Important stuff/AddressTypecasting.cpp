#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 65;
    char c = i; // This is "implicit typecasting"
    //(In this, the compiler automatically understands that u want to convert int to char and does it on its own.)

    cout << c << endl; // This will print 'A' since ascii value of this character is 65

    /*  int *p = &i;       Lines 12 and 13 will give error saying that int* cannot become char*
        char *pc = p;     Implicit typecasting not possible
    */
    int *p = &i;
    char *pc = (char *)p;

    cout << p << endl;  // address of int i
    cout << pc << endl; // since it's a character, it'll go to its designated address
    // and will start reading all characters until it reaches a null pointer
    // In our case, first char is "A" and then all are null pointers
    //(since there're 4 bytes for int but only 1 byte for char, so the rest 3 will be null pointers)

    cout << *p << endl;
    cout << *pc << endl;
    cout << *(pc + 1) << endl;
    cout << *(pc + 2) << endl;
    cout << *(pc + 3) << endl;

    return 0;
}