/*Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.

Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2

/////
2 -2 
-2 2
/////

Sample Input 2:
13
-2 -12 2 11 12 -2 1 -2 2 -11 12 2 6
Sample Output 2:
12
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int PairSum(int arr[], int n)
{
    int count = 0;
    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++)
    {
        int compliment = -arr[i];
        if (myMap.find(compliment) != myMap.end())
        {
            count += myMap[compliment];
        }
        myMap[arr[i]]++;
    }
    return count;
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

    cout << PairSum(arr, n) << endl;

    return 0;
}