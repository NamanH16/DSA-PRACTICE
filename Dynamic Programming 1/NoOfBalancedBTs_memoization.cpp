#include <iostream>
#include <vector>
#define ll long long
using namespace std;

long helper(int n, vector<int> &ans)
{
    ll mod = 1e9 + 7;
    if (n <= 1)
    {
        return 1;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    ll x = helper(n - 1, ans);
    ll y = helper(n - 2, ans);

    ll result = x * x + 2 * x * y;
    ans[n] = result % mod;
    return ans[n];
}

int balancedBTs(int n)
{
    // Write your code here
    vector<int> ans(n + 1, -1);
    return helper(n, ans);
}

int main()
{
    int h;
    cin >> h;
    cout << balancedBTs(h) << endl;
}