#include <iostream>
#include <string>
using namespace std;

int editDistance_DP(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    // Fill 1st row
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = j;
    }

    // Fill 1st column
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int x = output[i - 1][j];
                int y = output[i][j - 1];
                int z = output[i - 1][j - 1];
                output[i][j] = min(x, min(y, z)) + 1;
            }
        }
    }
    return output[m][n];
}

int main()
{
    string s;
    string t;
    cin >> s >> t;
    cout << editDistance_DP(s, t) << endl;
}