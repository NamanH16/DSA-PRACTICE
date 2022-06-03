#include <bits/stdc++.h>
using namespace std;
#define int long long

const vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> recursion(int n)
{
    if(n <= 1)
    {
        return {""};
    }
    
    vector<string> ans = recursion(n/10);
    vector<string>output;
    
    int index = n%10;
    for(char c:keypad[index])
    {
        for(string s: ans)
        {
            output.push_back(s+c);
        }
    }
    return output;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<string>ans = recursion(n);
        
        for(string s: ans)
        {
            cout << s << endl;
        }
    }
    return 0;
}