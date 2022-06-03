#include <iostream>
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

    int key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // placing element at the right position
    }

    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }

    delete[] arr;

    return 0;
}