#include <iostream>
#include <string>
using namespace std;

int editDistance_mem(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }

    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;
    if (s[0] == t[0])
    {
        ans = editDistance_mem(s.substr(1), t.substr(1), output);
    }
    else
    {
        int x = editDistance_mem(s.substr(1), t, output) + 1;
        int y = editDistance_mem(s.substr(1), t.substr(1), output) + 1;
        int z = editDistance_mem(s, t.substr(1), output) + 1;

        ans = min(x, min(y, z));
    }
    output[m][n] = ans;
    return ans;
}

int editDistance(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return editDistance_mem(s, t, output);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t) << endl;
}