/*Given k different arrays, which are sorted individually (in ascending order).
 You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.

Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    // Write your code here
    for (int i = 0; i < input.size(); i++)
    {
        vector<int> *q = input[i];
        for (int j = 0; j < q->size(); j++)
            pq.push(q->at(j));
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main()
{
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++)
    {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}