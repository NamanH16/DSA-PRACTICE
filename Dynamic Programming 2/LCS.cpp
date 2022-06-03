/*Longest Common Subsequence*/
#include <iostream>
#include <string>
using namespace std;

int LCS(string s, string t)
{
    // Base Case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    // Recursive Calls
    if (s[0] == t[0])
    {
        return 1 + LCS(s.substr(1), t.substr(1));
    }
    else
    {
        int a = LCS(s.substr(1), t);
        int b = LCS(s, t.substr(1));
        int c = LCS(s.substr(1), t.substr(1));

        return max(a, max(b, c));
    }
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << LCS(s, t) << endl;

    return 0;
}