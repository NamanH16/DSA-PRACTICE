/*
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/
#include <iostream>
#include <queue>
using namespace std;

void findMedian(int *arr, int n)
{
    if (n == 0)
    {
        return;
    }
    priority_queue<int> s;                            //max heap to store lesser half elements
    priority_queue<int, vector<int>, greater<int>> g; //min heap to store the greater half elements
    // Write your code here

    int med = arr[0];
    s.push(arr[0]);

    cout << med << " ";

    // reading elements of stream one by one

    for (int i = 1; i < n; i++)
    {
        int x = arr[i];

        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);

            med = (s.top() + g.top()) / 2.0;
        }

        // case2(both heaps are balanced)
        else if (s.size() == g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (int)s.top();
            }
            else
            {
                g.push(x);
                med = (int)g.top();
            }
        }

        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);

            med = (s.top() + g.top()) / 2.0;
        }

        cout << med << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    findMedian(arr, n);

    delete[] arr;
}
