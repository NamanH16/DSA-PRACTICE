#include <iostream>
using namespace std;

int helper(int arr[], int l, int r, int k)
{
    int mid = l + (r - l) / 2;

    if (l <= r)
    {
        if (arr[mid] == k)
        {
            return mid;
        }

        if (arr[mid] > k)
        {
            return helper(arr, l, mid - 1, k);
        }

        return helper(arr, mid + 1, r, k);
    }
    return -1;
}

int BinarySearch(int arr[], int n, int k)
{
    int ans = helper(arr, 0, n - 1, k);
    if (ans == -1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
    // NOTE: The array given is already sorted. Just binary search using recursion

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    cout << BinarySearch(arr, n, k) << endl;

    return 0;
}