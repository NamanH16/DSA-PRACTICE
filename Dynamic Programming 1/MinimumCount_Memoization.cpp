#include <iostream>
#include <vector>
using namespace std;

int helper(int n, vector<int> &ans)
{
    if (n <= 3)
    {
        return n;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int result = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        result = min(result, 1 + helper(n - i * i, ans));
    }
    ans[n] = result;
    return result;
}

int minCount(int n)
{
    vector<int> ans(n + 1, -1);
    return helper(n, ans);
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n) << endl;

    return 0;
}