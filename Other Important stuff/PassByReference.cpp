#include <bits/stdc++.h>
using namespace std;

void increment(int &k) // make 'k' a reference variable, now that it has the same memory as 'i',it'll affect int 'i' as well
{
    k += 11;
}

int main()
{
    int i = 10;

    increment(i);

    cout << i << endl;

    return 0;
}