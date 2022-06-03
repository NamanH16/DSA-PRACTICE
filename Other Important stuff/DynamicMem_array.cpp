#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int Max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > Max)
        {
            Max = arr[i];
        }
    }

    cout << Max << endl;

    return 0;
}