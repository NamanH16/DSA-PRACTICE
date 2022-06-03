#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    //Write your code here
    vector<int> ans(n + 1);
    ans[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int res = INT_MAX;
        for (int j = 1; j * j <= i; j++)
        {
            if ((i - j * j) >= 0)
                res = min(res, 1 + ans[i - j * j]);
        }
        ans[i] = res;
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n) << endl;
    return 0;
}