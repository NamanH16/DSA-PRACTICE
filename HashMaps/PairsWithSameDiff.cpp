/*You are given with an array of integers and an integer K.
You have to find and print the count of all such pairs which have difference K.

Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2 5 
1 4

Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4*/
#include <iostream>
#include <unordered_map>
using namespace std;

void printPairs(int *input, int n, int k)
{
    if (k < 0)
        k *= -1; // k is positive
    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++)
    {
        int solutionBig = input[i] + k;
        int solutionSmall = input[i] - k;
        if (myMap.count(solutionBig))
        {
            int count = myMap[solutionBig]; // print count times
            for (int j = 0; j < count; j++)
                cout << input[i] << ' ' << solutionBig << endl;
        }
        if (k && myMap.count(solutionSmall))
        {
            int count = myMap[solutionSmall]; // print count times
            for (int j = 0; j < count; j++)
                cout << solutionSmall << ' ' << input[i] << endl;
        }
        myMap[input[i]]++;
    }
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
    printPairs(arr, n, k);

    return 0;
}