/*
Sample Input 1:
8
42 20 18 6 14 11 9 4

Sample Output 1:
true*/
#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    // Write your code here
    for (int i = 0; i <= (n - 2) / 2; i++) // Considering that i as ParentIndex, its index should always be lesser than both its childIndex
    {
        int parentIndex = i;
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        if (arr[leftChildIndex] > arr[parentIndex] || arr[rightChildIndex] > arr[parentIndex] && rightChildIndex < n)
        {
            return false;
        }
    }
    return true;
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

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}