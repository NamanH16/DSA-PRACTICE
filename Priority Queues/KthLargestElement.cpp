/*
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9

Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthLargest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    // Write your code here
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
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

    cout << kthLargest(arr, n, k);

    delete[] arr;
}