#include <iostream>
using namespace std;

//Approach 3: Dynamic Programming
long staircase(int n)
{
    long long int *dp = new long long int[n + 1];

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    long long int ans = dp[n];
    return ans;
    delete[] dp;
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n) << endl;

    return 0;
}