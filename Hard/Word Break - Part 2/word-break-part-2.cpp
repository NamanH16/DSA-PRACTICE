//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(string s,set<string>st, vector<string>&ans, string curr,int i){
        if(i==s.size()){
            curr.pop_back(); // remove extra space from last word
            ans.push_back(curr);
            return;
        }
        string temp="";
        while(i<s.size()){
            temp+=s[i];
            if(st.count(temp)){
                solve(s,st,ans,curr+temp+" ",i+1);
            }
            i++;
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        set<string> st(dict.begin(),dict.end());
        vector<string> ans;
        solve(s,st,ans,"",0);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends