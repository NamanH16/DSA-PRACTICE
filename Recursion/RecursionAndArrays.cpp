// Recursive problem : give out true if the array is sorted,otherwise false
#include <iostream>
using namespace std;

bool is_sorted(int a[], int size)
{
    if (size == 0 || size == 1) //(base cases) : if size of array is 0 or 1, then it's sorted.
    {
        return true;
    }
    if (a[0] > a[1]) // It isn't a base case. Only comparison between the 0th and 1st element is being done.
    {                // if 0th element is larger than 1st element, then the array is obviously not sorted
        return false;
    }
    bool is_smallerSorted = is_sorted(a + 1, size - 1); // if first 2 elements are sorted, that's why we're checking for the
    return is_smallerSorted;                            // rest of the array
}
/*
bool is_sorted2(int a[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    bool smallerSorted = is_sorted2(a + 1, size - 1);
    if (!smallerSorted)
    {
        return false;
    }
    if (a[0] > a[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}*/

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << is_sorted(a, n) << endl;
    //cout << is_sorted2(a, n) << endl;
}