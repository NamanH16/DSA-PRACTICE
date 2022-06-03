/*We will be given an array along with an integer k. The array is almost sorted, given that the unsorted elements can be anywhere 
just at a distance k-1 either to the left or the right. Sort the k sorted array*/
#include <iostream>
#include <queue>
using namespace std;

void KsortedArray(int input[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main()
{
    int arr[] = {12, 15, 6, 7, 9};
    int k;
    cin >> k;
    int n = sizeof(arr) / sizeof(arr[0]);
    KsortedArray(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}