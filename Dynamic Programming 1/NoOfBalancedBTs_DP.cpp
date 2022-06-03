#include <iostream>
#define ll long long
using namespace std;

int balancedBTs(int n)
{
    // Write your code here
    ll mod = 1e9 + 7;
    long long int ans[n + 1];
    ans[1] = 1;
    ans[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        ans[i] = ((ll)(ans[i - 1]) * ans[i - 1]) % mod + (2 * (ll)(ans[i - 1]) * ans[i - 2]) % mod;
    }

    return ans[n] % mod;
}

int main()
{
    int h;
    cin >> h;
    cout << balancedBTs(h) << endl;
}