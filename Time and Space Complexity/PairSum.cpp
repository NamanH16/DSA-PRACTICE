#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr, int n, int k)
{
    sort(arr, arr + n);

    int i = 0;
    int j = n - 1;

    int ans = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] == k)
        {
            int e = n - 1;
            while (e > i && arr[e] == arr[j]) // checking for duplicates
            {
                e--;
                ans++;
            }
            i++;
        }
        else if (arr[i] + arr[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << pairSum(input, n, k) << endl;

    delete[] input;
}