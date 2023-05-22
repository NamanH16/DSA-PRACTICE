class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto element:mp){
            pq.push({element.second, element.first}); //priority queue where the elements are pairs of the frequency count and element value, sorted in descending order of frequency count
        }
        vector<int>ans;
        while(ans.size() < k){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};