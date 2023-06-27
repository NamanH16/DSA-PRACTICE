class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        priority_queue<pair<int,pair<int,int>>> pq; // sum with a[i] & b[j]
        int n=a.size(), m=b.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=a[i]+b[j];
                if(pq.size()<k){
                    pq.push({sum, {a[i], b[j]}});                    
                }else if(pq.top().first>sum){
                    pq.pop();
                    pq.push({sum, {a[i], b[j]}});
                }else{
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};