#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int k)
{
    int ans = 0;

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        int num = k - arr[i];

        int s = i + 1;
        int e = n - 1;

        while (s < e)
        {
            if (arr[s] + arr[e] == num)
            {
                int index = e;
                while (index > s && arr[index] == arr[e])
                {
                    index--;
                    ans++;
                }
                s++;
            }
            else if (arr[s] + arr[e] > num)
            {
                e--;
            }
            else
            {
                s++;
            }
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

    cout << tripletSum(input, n, k) << endl;

    delete[] input;
}