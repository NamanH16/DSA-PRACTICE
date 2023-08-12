class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size(),-1);
        int n = nums2.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top();
            }
            st.push(nums2[i]);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=nge[i];
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};