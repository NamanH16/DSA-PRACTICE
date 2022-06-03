/*
You are given with an integer k and an array of integers that contain numbers in random order. 
Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

Sample Output 1 :
1 2 3 5 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> kSmallest(int input[], int n, int k)
{
    priority_queue<int> min;
    vector<int> v;

    for (int i = 0; i < k; i++)
    {
        min.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (min.top() > input[i])
        {

            min.pop();
            min.push(input[i]);
        }
    }

    while (!min.empty())
    {
        v.push_back(min.top());
        min.pop();
    }
    return v;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
}