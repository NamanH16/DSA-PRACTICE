//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void solve(string s, vector<string>&ans, int i,int n){
            if(i>=n-1){
                ans.push_back(s);
                return;
            }
            for(int j=i;j<n;j++){
                swap(s[i],s[j]);
                solve(s,ans,i+1,n);
                swap(s[i],s[j]);
            }
        }
        
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int n = S.length();
		    vector<string> ans;
		    solve(S, ans, 0,n);
		    sort(ans.begin(),ans.end());
		    ans.erase(unique(ans.begin(),ans.end()), ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends