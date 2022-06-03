#include <iostream>
#define ll long long
using namespace std;

// Brute Force: REcursive Solution
int balancedBTs(int n)
{
    // Write your code here
    ll mod = 1e9 + 7;

    if (n <= 1)
    {
        return 1;
    }

    ll x = balancedBTs(n - 1);
    ll y = balancedBTs(n - 2);

    ll ans = x * x + 2 * x * y;
    return ans % mod;
}

int main()
{
    int h;
    cin >> h;
    cout << balancedBTs(h) << endl;
}
