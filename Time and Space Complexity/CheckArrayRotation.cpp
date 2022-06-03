#include <iostream>
using namespace std;

int checkrotation(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }

    int min_ind;
    int minN = arr[0]; // since there's no previous element, if array isn't rotated, then it would've been minimum

    for (int i = 0; i < n; i++)
    {
        if (minN > arr[i])
        {
            minN = arr[i];
            min_ind = i;
        }
    }
    return min_ind; // basically returns the index of the minimum number in the array
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = checkrotation(arr, n);

    cout << ans << endl;

    delete[] arr;

    return 0;
}