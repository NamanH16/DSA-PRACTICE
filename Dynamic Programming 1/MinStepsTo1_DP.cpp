// Approach 3: Dynamic Programming
#include <iostream>
using namespace std;

int minStepsTo1(int n)
{
    int *ans = new int[n + 1];
    ans[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        int x = ans[i - 1];
        int y = INT_MAX;
        int z = INT_MAX;

        if (i % 2 == 0)
        {
            y = ans[i / 2];
        }

        if (i % 3 == 0)
        {
            z = ans[i / 3];
        }
        ans[i] = 1 + min(x, min(y, z));
    }
    int result = ans[n];
    delete[] ans;
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << minStepsTo1(n) << endl;
}