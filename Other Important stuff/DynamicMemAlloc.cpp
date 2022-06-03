#include <iostream>
using namespace std;

int main()
{
    int *p = new int;
    *p = 10;
    cout << *p << endl;

    double *pd = new double;

    char *c = new char;

    int *pa = new int[50]; //8 bytes on the stack and 200 bytes on heap
    int n;
    cin >> n;
    int *pa2 = new int[n];
    // Now pa2 can be treated just as a normal array. Eg: pa2[0] = 1;

    return 0;
}