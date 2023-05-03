//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define pb push_back
class Solution
{
private:
    void solve(vector<vector<int>> &ans, vector<int>&v,vector<vector<int>> grid,int i,int j,int n,int m){
        if(i==n-1 && j==m-1){
            v.pb(grid[i][j]);
            ans.pb(v);
            v.pop_back();
            return;
        }
        if(i>=n)return;
        if(j>=m)return;
        v.pb(grid[i][j]);
        solve(ans,v,grid,i+1,j,n,m);
        solve(ans,v,grid,i,j+1,n,m);
        v.pop_back();
    }
    
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans,v,grid,0,0,n,m);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends