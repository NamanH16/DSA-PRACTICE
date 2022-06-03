//Characters and pointers
#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4}; // There's a difference between int arr and char arr
    char b[] = "abc";

    cout << a << endl; // Here the address of int a[] will be printed
    cout << b << endl; // Here the whole string will be printed until met by '\0' at the end of the string

    char *c = &b[0];
    cout << c << endl; // Even tho it's pointing towards b[0], it's print the whole string 'b'

    char c1 = 'a';
    char *pc = &c1;

    cout << c1 << endl;
    cout << pc << endl; // this will try to print random garbage string after the character
    //until it reaches '\0'(null char present at the end of every string)

    return 0;
}