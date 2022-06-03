#include <iostream>
using namespace std;

int sum(int a[], int n) // This is fraud!! Not sayin that it won't work, but it's just that array is being passed as a pointer
// Therefore this function may also be written as "int sum(int *a,int n)"
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k += a[i];
    }

    return k;
}

int main()
{
    int a[10];

    cout << sum(a, 10) << endl; //Here a is essentially pointing towards a[0]
    // part of an array may also be passed
    // something like sum(a+3,7) || Here it's pointing towards a[3] will give me the sum of that part of the array

    return 0;
}