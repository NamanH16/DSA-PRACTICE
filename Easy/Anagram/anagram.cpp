//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());
        // return a==b;
        if(a.length()!=b.length())return false;
        unordered_map<char, int> mp;
        for(char x:a){
            mp[x]++;
        }
        int cnt=0;
        for(char m:b){
            if(mp.find(m)!=mp.end()){
                mp[m]--;
            }else{
                return false;
            }
        }
        for(auto x:mp){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends