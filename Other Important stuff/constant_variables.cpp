#include <iostream>
using namespace std;

int main()
{
    const int i = 10;  // this doesn't mean that the memory has become constant, it means the path has become constant
    int const i2 = 10; // both 'const int' and 'int const' are same

    // constant reference from a non const int
    int j = 12;
    int const &k = j;

    j++;
    //k++; not allowed since the path of k to address is constant
    cout << k << endl; // 13

    /*-------------------------------------------------------*/
    // constant reference from a constant int
    const int t = 11;
    const int &l = t;
    /*-------------------------------------------------------*/
    //reference from a constant int
    const int a = 15; // 'const' is a read-only path
    //int &p = a;[ERROR]       // Therefore, i cannot create a writable path to p(since i myself don't have the authority)

    //p++;  will give error

    return 0;
}