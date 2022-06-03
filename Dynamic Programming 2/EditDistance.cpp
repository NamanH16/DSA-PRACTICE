/*Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. 
In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character*/
#include <iostream>
#include <string>
using namespace std;

int editDistance(string s, string t)
{
    // Base Case
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }

    if (s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }
    else
    {
        // Insert
        int x = editDistance(s.substr(1), t) + 1;
        // Delete
        int y = editDistance(s, t.substr(1)) + 1;
        // Replace
        int z = editDistance(s.substr(1), t.substr(1)) + 1;

        return min(x, min(y, z));
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t) << endl;
}