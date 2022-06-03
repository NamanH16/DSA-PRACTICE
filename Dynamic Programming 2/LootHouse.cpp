/*A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses.
Find the maximum amount of money he can loot.
 
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

Sample Input 1 :
6
10 2 30 20 3 50
Sample Output 1 :
90

Explanation of Sample Output 1 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, 
and all the other possible combinations would result in less than 90.

Sample Input 2 :
6
5 5 10 100 10 5
Sample Output 2 :
110

Explanation of Sample Output 2 :
Looting first, fourth, and the last houses([5 + 100 + 5]) will result in the maximum loot, 
and all the other possible combinations would result in less than 110.
*/
#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
    int dp[n];
    //Write your code here
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]); // we are asking for maximum between
                                                    //1) max till the index i-1...meaning that we're excluding the ith index
    }                                               // 2) max till ith index... we cannot take any consecutive house
                                                    //so we can add arr[i] to max till i-2th index
    return dp[n - 1];
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

    cout << maxMoneyLooted(arr, n);

    return 0;
}