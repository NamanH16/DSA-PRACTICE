// Using function normally isn't the best way since the program will be paused in middle. Then values of a and b will be copied in the
// function and then the answer will come down from the function (Function call overhead)
// That's why we can use inline funtion to reduce function call overhaed
// What is Inline Function ?
// This function basically copies the whole code present in the function(line 11) at the place of use,i.e, lines 19 and 25.
#include <iostream>
using namespace std;

// NOTE : inline function will generally work only for 1 line code. Whether it wanna work for 2-3 lines or not, that'd be completely
// the compiler's choice
// Also, if u make a 50 line code as an inline function(although compiler won't do it), the output file will be really bulky
// Since that 50 line code is being copied to everywhere it's being called !!
inline int Maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int c = Maximum(a, b); // Here, Maximum function will be replaced by line 11
    cout << c << '\n';

    int x = 12;
    int y = 13;

    cout << Maximum(x, y) << endl; // Here, Maximum function will be replaced by line 11

    return 0;
}