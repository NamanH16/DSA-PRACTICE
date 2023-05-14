class Solution {
private:
    int solve(vector<int>&nums, vector<bool>&vis, int i,unordered_map<vector<bool>,int>&mp){
        if(mp.count(vis)) return mp[vis];
        int mxscore=0;
        for(int j=0;j<nums.size()-1;j++){
            if(vis[j])continue;
            for(int k=j+1;k<nums.size();k++){
                if(vis[k])continue;
                vis[j]=true;
                vis[k]=true;
                int currscore = i*__gcd(nums[j],nums[k]);
                int nextmxscore = solve(nums,vis,i+1,mp);
                int totalscore = currscore+nextmxscore;
                mxscore=max(mxscore,totalscore);
                vis[j]=false;
                vis[k]=false;
            }
        }
        return mp[vis]=mxscore;
    }
    
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);
        unordered_map<vector<bool>,int>mp;
        int ans = solve(nums,visited,1,mp);
        return ans;
    }
};