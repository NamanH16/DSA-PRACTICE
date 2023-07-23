class Solution {
private:
    void solve(int i,vector<int> candidates, int target,vector<int> output,vector<vector<int>> &ans){
        if(i>=candidates.size()){
            if(target==0){
                ans.push_back(output);
            }
            return;
        }
        // notTake
        solve(i+1, candidates, target, output, ans);
        
        // take
        if(candidates[i]<=target){
            output.push_back(candidates[i]);
            solve(i, candidates, target-candidates[i], output, ans);
            output.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        solve(0,candidates,target,out,ans);
        return ans;
    }
};