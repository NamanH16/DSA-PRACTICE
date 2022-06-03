/*You are given an array of integers that contain numbers in random order. 
Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2

Sample Input 2 :
3
1 4 5
Sample Output 2 :
1*/
#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int *arr, int n)
{
    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++) // mapping elements with their frequencies
    {
        myMap[arr[i]]++;
    }

    int maximum = myMap[arr[0]];
    int ans = arr[0];
    int j = 0;
    while (j < n)
    {
        if (myMap[arr[j]] > maximum)
        {
            maximum = myMap[arr[j]];
            ans = arr[j];
        }
        j++;
    }
    return ans;
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

    cout << highestFrequency(arr, n) << endl;

    delete[] arr;
}