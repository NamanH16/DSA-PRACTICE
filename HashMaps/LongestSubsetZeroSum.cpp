/*Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    // Write your code here
    int maxLength = 0;
    vector<int> sum;
    unordered_map<int, int> m; // stores sum and index
    sum.push_back(arr[0]);
    m[arr[0]] = 0;
    if (arr[0] == 0)
    {
        maxLength = 1;
        //startIndex = endIndex = 0;
    }
    for (int i = 1; i < n; i++)
    {
        sum.push_back(sum[i - 1] + arr[i]);
        if (sum[i] == 0)
        {
            //start = 0;
            //endIndex = i;
            maxLength = i + 1;
        }
        else if (m.count(sum[i]))
        {
            if (i - m[sum[i]] > maxLength)
                maxLength = i - m[sum[i]];
            //startIndex = m[sum[i]];
            //endIndex = i;
        }
        else
            m[sum[i]] = i;
    }
    return maxLength;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}