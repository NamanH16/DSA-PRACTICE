#include <iostream>
using namespace std;

void rotate(int *arr, int n, int k)
{
    int temp[k + 1];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + k];
    }

    int l = 0;
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[l];
        l++;
    }
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

    int k;
    cin >> k;

    rotate(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}