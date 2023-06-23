//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> count (string s)
        {
            //code here.
            int n = s.length();
            vector<int> ans;
            int a=0, b=0, c=0, d=0;
            for(int i=0;i<n;i++){
                if(s[i]>='A' && s[i]<='Z'){
                    a++;
                }else if(s[i]>='a' && s[i]<='z'){
                    b++;
                }else if(isdigit(s[i])){
                    c++;
                }else{
                    d++;
                }
            }
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(c);
            ans.push_back(d);
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        vector <int> res = ob.count (s);
        for (int i : res)
            cout << i << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends