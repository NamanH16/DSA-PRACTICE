/*
#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int &j = i;

    i++;
    cout << j << endl;

    return 0;
}*/
#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int &j = i;
    int k = 50;
    j = k;

    i++;
    cout << i << '\n'
         << j << '\n'
         << k << endl;

    return 0;
}