#include <iostream>
using namespace std;

long helper(int n, long long int *ans)
{
    // Base Case
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }

    // Check if output already exists
    if (ans[n] != -1)
    {
        return ans[n];
    }

    // Calculating output
    long long int output = helper(n - 1, ans) + helper(n - 2, ans) + helper(n - 3, ans);

    ans[n] = output;

    return output;
}

long staircase(int n)
{
    long long int *ans = new long long int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return helper(n, ans);
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n) << endl;

    return 0;
}